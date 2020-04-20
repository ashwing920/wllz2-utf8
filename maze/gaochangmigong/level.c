// Room: /d/taohua/thmz.c

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	set_maze_npcs( ([
		__DIR__"npc/duxie":random(2),
		__DIR__"npc/shamang":random(2),
		__DIR__"npc/mazei":random(3),
		__DIR__"npc/mazeitouzi":random(5),
	]) );

	//迷宫内出现生物的随机度
	set_npcs_rate(80);
	set_lonely_create(1);
	//迷宫出现生物个数
	//set_char_num(8);

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"main1");

	//出口与区域的连接方向
	set_link_exit_dir("northwest");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"main2");

	//入口房间短描述
	set_entry_short("高昌迷宫");

	//入口房间描述
	set_entry_desc(@LONG
$YEL$你走进洞窟当中，借着微弱的光线，洞窟中的黄土遍布，洞中路道弯
弯曲曲，诡异非常。洞里一片寂静，偶尔从洞里传来阵阵悉悉嗦嗦的声响。
洞穴里的空气已经逐渐稀薄，仿佛要让人窒息一般。$NOR$
LONG
);

	//出口房间短描述
	set_exit_short("高昌迷宫");

	//出口房间描述
	set_exit_desc(@LONG
$YEL$这里的洞窟的末端，一道石壁挡在你的面前，洞窟的石壁上刻满了一
些蝌蚪般大小的字，弯弯曲曲奇形怪状，你怎么也看不明白究竟写了些什
么东西。石壁那边不时传来咔哒咔哒的声响，仿佛石壁那边又是另外一片
天地。$NOR$
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("高昌迷宫");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
$YEL$你来到一个黄土夯成洞窟之中。洞窟两边的石壁上和洞顶，星点的布
满了一个个小洞，石壁上有一些全身褐色的虫子正在石壁上的小洞里穿梭
，不时发出悉悉嗦嗦的声响。洞里光线昏暗，只有洞顶的几个小洞射来道
道光束。往洞里望去，黑糊糊的一片，不时闪过一个黑影，不知是幻觉，
还是人影，你不知不觉的已经迷失在洞窟当中。$NOR$
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
