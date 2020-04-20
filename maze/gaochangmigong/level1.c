// Room: /d/taohua/thmz.c

#include <ansi.h>

inherit VRM_SERVER;

void create()
{
	// 迷宫房间所继承的物件的档案名称。
	set_inherit_room(ROOM);

	//迷宫房间里的怪物。
	
	set_maze_npcs( ([
		__DIR__"npc/yinshi":random(2),
		__DIR__"npc/shamang":random(2),
		__DIR__"npc/laogui":random(3),
		__DIR__"npc/mazeiwang":random(5),
		__DIR__"npc/mengmianshashou":random(5),
	]) );
	/*
	set_maze_npcs(__DIR__"npc/shamang");
	set_maze_npcs(__DIR__"npc/yinshi");
	set_maze_npcs(__DIR__"npc/mazeiwang");
	set_maze_npcs(__DIR__"npc/laogui");
	set_maze_npcs(__DIR__"npc/mengmianshashou");
	*/
	//迷宫内出现生物的随机度
	set_npcs_rate(50);
	set_lonely_create(1);

	//迷宫的单边长
	set_maze_long(10);

	//入口方向(出口在对面)
	set_entry_dir("south");

	//入口与区域的连接方向
	set_link_entry_dir("south");

	//入口与区域的连接档案名
	set_link_entry_room(__DIR__"main2");

	//出口与区域的连接方向
	set_link_exit_dir("north");

	//出口与区域的连接档案名
	set_link_exit_room(__DIR__"xiaowu");

	//入口房间短描述
	set_entry_short("高昌迷宫");

	//入口房间描述
	set_entry_desc(@LONG
$YEL$这里又是洞窟内的另外一番天地，甬道比原先宽敞多了，可能是由于
洞窟深处的关系，这里的空气已经逐渐稀薄。洞窟中的地面稀疏的残留着
几个脚印，陆陆续续的往洞窟内一直延伸。$NOR$
LONG
);

	//出口房间短描述
	set_exit_short("高昌迷宫");

	//出口房间描述
	set_exit_desc(@LONG
$YEL$你来到洞窟深处的甬道，可能是处于洞窟的深处，地面的黄土变得已
经十分的结实。洞窟的两边石壁上，分别有一个足有半人高的石窟，石窟
里陈列着一座佛像。有的闭目养神，有的坐禅念佛，栩栩如生，活灵活现
。前面有一个黄土的大门，好像是一个房间。$NOR$
LONG
);

	//迷宫房间的短描述
	set_maze_room_short("高昌迷宫");

	//迷宫房间的描述，如果有多条描述，制造每个房
	//间的时候会从中随机选择一个。
	set_maze_room_desc(@LONG
$YEL$你来到洞窟深处的甬道，可能是处于洞窟的深处，地面的黄土变得已
经十分的结实。洞窟的两边石壁上，分别有一个足有半人高的石窟，石窟
里陈列着一座佛像。有的闭目养神，有的坐禅念佛，栩栩如生，活灵活现
。$NOR$
LONG
);
	// 迷宫房间是否为户外房间？
	set_outdoors(0);
}
