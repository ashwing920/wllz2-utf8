// private_room.c
// Written by Doing Lu 1998/11/16
//    私有房间是提供给玩家的房间需要继承的属性，它主要具有以下的属性:
//    首先，如果需要清除时(clean_up被调用)，它要保存这个对象及这个房间内的所有可以
//    保存的物品(具有AUTOLOAD属性的)。
//    其次，这个房间会在load的时候自动的调入保存在磁盘上的对象数据，当然首先要检查
//    是否有存盘数据。

// 这个文件继承了原有的ROOM，并修订了一些函数。

#include <room.h>

inherit ROOM;
inherit F_SAVE;
inherit F_AUTOLOAD;

// 返回object存档的名字
string query_save_file()
{
	string file;
	file = base_name(this_object());
	if (file[0..10] != "/data/room/") file = "/data/room" + file;

	return file;
}

// save过程可以保存这个房间内的所有autoload的物品。
int save()
{
	// 如果是室外，不予存储
	if (query("outdoors")) return 1;

	save_autoload();
	return ::save();
}

// 回复房屋内的物品
int restore()
{
	// 如果是室外，不予读取
	if (query("outdoors")) return 0;

	::restore();
	return restore_autoload();
}

// 这是一个非常重要的函数，系统每隔一定时间(通常是15分钟)就会调用这个函数，
// 如果返回0，系统将不再调用这个函数，如果返回的是1，就在下一个间隔调用这个
// 函数。
int clean_up()
{
	object *inv;
	int i;

	// 如果这个房屋内有玩家就不清除
	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
		if(interactive(inv[i])) return 1;

	// 保存并清除这个房间
	save();
	destruct(this_object());
	return 0;
}

// 建立房屋
int setup()
{
	// 设置私有房间标志
	set("private_room", 1);

	::setup();

	if (! query("outdoors") && file_size(query_save_file() + __SAVE_EXTENSION__) != -1)
	{
		// 如果有存档并且是室内，则取存档数据
		restore();
	}
	return 1;
}

// 修正继承的ROOM
string look_door(string dir)
{
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "你要看什么？\n";
	if( doors[dir]["status"] & DOOR_CLOSED )
		return "这个" + doors[dir]["name"] + "是关着的，上面有一个钥匙孔。\n";
	else
		return "这个" + doors[dir]["name"] + "是开着的。\n";
}

// 修正继承的ROOM
varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;
	object me;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("这个方向没有门。\n");

	if( !(doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "已经是开着的了。\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
	{
		message("vision", "有人从另一边将" + doors[dir]["name"] + "打开了。\n", this_object());
	}
	else
	{
		me = this_player();
		if (! stringp(query("key")) || ! objectp(ob = present(query("key"), me)))
		{
			message_vision("$N上前推了推，但是门纹丝不动。\n", me);
			return notify_fail("看来你得找到钥匙才行。\n");
		}
		if (! objectp(ob = find_object(exits[dir])));
			ob = load_object(exits[dir]);
		if (! objectp(ob)) return 0;

		if (! ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
		message_vision("$N掏出钥匙，插入钥匙孔扭了几下。\n", me);
	}
	doors[dir]["status"] &= (!DOOR_CLOSED);
	return 1;
}
