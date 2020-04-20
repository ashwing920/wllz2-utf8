// Room: /d/taohua/thmz.c
// 桃花迷阵

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	//set_maze_npcs(__DIR__"npc/maque");

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("north");

	//入口与区域的连接方向
	set_link_entry_dir("north");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"haitan");

	//出口与区域的连接方向
	set_link_exit_dir("south");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"damen");

	//入口房间短描述
	set_entry_short("桃花迷阵");

	//入口房间描述
	set_entry_desc(@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花，微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。你心中不禁慌乱起来
：还是早点出去的好。
LONG
);

	//出口房间短描述
	set_exit_short("试剑亭");

	//出口房间描述
	set_exit_desc(@LONG
这里是一个用白玉石砌成的亭子，亭子砌得小巧玲珑，十分精巧。亭
子的北面是一片桃花林，南面则是桃花山庄的正门。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("桃花迷阵");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花，微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。你心中不禁慌乱起来
：还是早点出去的好。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}
