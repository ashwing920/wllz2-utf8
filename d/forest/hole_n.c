// Room: /d/taohua/thmz.c

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	set_maze_npcs(__DIR__"npc/tuying");
	set_maze_npcs(__DIR__"npc/bianfu");
	set_maze_npcs(__DIR__"npc/dushe");
	
	//迷宫内出现生物的随机度
	set_random_rate(50);
	
	//迷宫出现生物个数
	set_char_num(5);

	//迷宫的单边长
	set_maze_long(20);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"hole07");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"hole10");

	//入口房间短描述
	set_entry_short("洞中岔路");

	//入口房间描述
	set_entry_desc(@LONG
你来到了洞中的岔路之中，路道已经逐渐变窄了。由于处于山洞的深
处，洞里一片漆黑，连一丝丝光线也没有。偶然一阵啪嗒啪嗒的声响从你
身边飞过，一切显得更加诡异。
LONG
);

	//出口房间短描述
	set_exit_short("洞中岔路出口");

	//出口房间描述
	set_exit_desc(@LONG
你来到岔路的深处，眼前出现了一个十分宽敞的洞庭。洞庭四周的墙
壁上，倚靠着几具已经干枯的骸骨，从骸骨上看去，想必已经是死去很久
了。有的骸骨已经残缺不齐，象是掉落，又象是被野兽所蚕食。
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("洞中岔路");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
你来到了洞中的岔路之中，路道已经逐渐变窄了。由于处于山洞的深
处，洞里一片漆黑，连一丝丝光线也没有。偶然一阵啪嗒啪嗒的声响从你
身边飞过，洞中不时更传出一阵野兽的嚎叫声，一切显得更加诡异，恐怖。
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
