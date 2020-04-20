// Recordable_room.c 可记录房间
// Written by Doing Lu 1998/11/16
//    可记录房间具有能够保存对象数据的能力，这主要是提供给场景需要做永久性变化的地
//    方，如玩家自选的建房地点。对MUDLIB中关于这个ROOM的操作要严格控制，因为这将修
//    改MUDLIB的场景，严禁不雅观的描述和会引起系统不正常运作的描述出现，因此，凡是
//    具有这个属性的场景当玩家需要修改时，应该上报巫师，经arch以上的巫师批准后方可
//    做出修改操作。
//
//    在继承Recordable_room 时，如果有init函数，必须继承使用这里提供的init函数，即
//    init函数中应该有::init的调用，而且不能使用replace_room函数。
inherit ROOM;
inherit F_SAVE;

mapping	user_room;

// 存放玩家自造房间的数据，mapping 存放的是 房间名 : 入口的文件路径
// 例如：听涛居 : /d/room/doing/????.c

// 返回object存档的名字
string query_save_file()
{
	return "/data/room" + base_name(this_object()) + ".sav";
}

// 修正long描述并生成xiaoyuan的描述
void create_desc()
{
	string	desc, ext_long;
	string* uroom;
	int	count;
	int	i;

	delete("item_desc/xiaoyuan");
	ext_long = "";
	if (mapp(user_room))
	{
		// 如果这里建有房间，修改long的提示信息
		count = 0;
		desc = "那里好像有：\n";
		uroom = keys(user_room);
		for (i = 0; i < sizeof(uroom); i++)
		{
			if (!stringp(uroom[i]) || uroom[i] == "") continue;
			count++;
			if (count > 1)
			{
				if ((count-1) % 4 == 0) desc += "\n          "; else desc += "\t";
			}
			desc += uroom[i];
		}
		desc += "。";
		if (count > 0)
		{
			if (count > 1)
			{
				ext_long = "    这里隐隐约约座落着几个小院(xiaoyuan)。\n";
			} else
			{
				ext_long = "    这里隐隐约约的座落着一个小院(xiaoyuan)。\n";
			}
			set("item_desc/xiaoyuan", desc + "\n");
		}
	} else
	{
		// 如果没有定义user_room, 置为空
		user_room = ([ ]);
	}
	set("long", query("old_long") + ext_long);
}

// 读取记录的数据，并且根据玩家自建的房屋添加提示信息
void setup()
{
	string old_long;

	old_long = query("long");
	if (file_size(query_save_file() + __SAVE_EXTENSION__) != -1)
	{
		// 如果有存档则取存档数据
		restore();
	}
	set("old_long", old_long);
	set("recordable_room", 1);
	create_desc();

	::setup();
}

// 初始化进入时的状态
void init()
{
	// 增加进入房间的函数
	add_action("do_enter", "enter");
	add_action("do_enter", "进入");
}

// 增加一套房间
int create_room(string room_name, string path)
{
	if (! mapp(user_room)) user_room = ([ ]);
	if (! stringp(room_name) || room_name == "") return 0;
	if (! undefinedp(user_room[room_name])) return 0;
	user_room[room_name] = path;
	create_desc();
	return 1;
}

// 判断是否存在一套房间
int exist_room(string room_name)
{
	if (! mapp(user_room)) return 0;
	if (! stringp(room_name) || room_name == "") return 0;
	if (undefinedp(user_room[room_name])) return 0;
	return 1;
}

// 去除一套房间
int demolish_room(string room_name)
{
	if (! mapp(user_room)) return 1;
	if (! stringp(room_name) || room_name == "") return 0;
	if (undefinedp(user_room[room_name])) return 0;
	map_delete(user_room, room_name);
	create_desc();
	return 1;
}

// 进入一套房间的入口处
int do_enter(string room_name)
{
	object me;
	object ob;
	
	me = this_player();
	if (! stringp(room_name) || room_name == "" || 	! mapp(user_room))
	{
		return notify_fail("你想去哪里？\n");
	}
	if (undefinedp(user_room[room_name]))
	{
		tell_object(me, "你左瞅瞅，右看看，也没找到那地方。\n");
		message("vision", me->query("name") +
			"左瞅瞅，右看看，鬼鬼祟祟的不知道在干些什么。\n", environment(me), ({me}));
		return 1;
	}
	if (! (ob = find_object(user_room[room_name])))
	{
		ob = load_object(user_room[room_name]);
		if (! objectp(ob))
		{
			write (user_room[room_name] + "\n");
			message_vision("$N快步向" + room_name + "走去，结果一头撞到铁板...快请巫师看看！\n", me);
			return 1;
		}
	}
	tell_object(me, "你快步向" + room_name + "走去。\n");
	message("vision", me->query("name") +
			"向" + room_name + "飘然而去。\n", environment(me), ({me}));
	me->move(ob);
	return 1;
}
