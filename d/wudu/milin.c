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
	set_maze_long(5);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"qiaobi5");

	//出口与区域的连接方向
	set_link_exit_dir("west");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"xiaolu");

	//入口房间短描述
	set_entry_short("密林");

	//入口房间描述
	set_entry_desc(@LONG
这是一片茂密的森林，参天的巨木遮住了光线，显的十分的暗淡，走
在这样的地方，你得是分小心，不时会有毒蛇猛兽出没，如果没有极大的
胆量，还是快回头吧。
LONG
);

	//出口房间短描述
	set_exit_short("密林");

	//出口房间描述
	set_exit_desc(@LONG
这是一片茂密的森林，参天的巨木遮住了光线，显的十分的暗淡，走
在这样的地方，你得是分小心，不时会有毒蛇猛兽出没，你似乎迷失了方
向。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("密林");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
这是一片茂密的森林，参天的巨木遮住了光线，显的十分的暗淡，走
在这样的地方，你得是分小心，不时会有毒蛇猛兽出没，你似乎迷失了方
向。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(1);
}
