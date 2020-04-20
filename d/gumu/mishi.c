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
	set_entry_dir("west");

	//入口与区域的连接方向
	set_link_entry_dir("west");
	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"mishi2");

	//出口与区域的连接方向
	set_link_exit_dir("east");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"qinshi");

	//入口房间短描述
	set_entry_short("古墓密室");

	//入口房间描述
	set_entry_desc(@LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯光来
勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，你难以
从中找出一丝缝隙。墙上好象雕有一些飞禽。
LONG
);

	//出口房间短描述
	set_exit_short("古墓密室");

	//出口房间描述
	set_exit_desc(@LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯光来
勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，你难以
从中找出一丝缝隙。东面好象有一丝光线。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("古墓密室");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯光来
勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，你难以
从中找出一丝缝隙。墙上好象雕有一些飞禽。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
