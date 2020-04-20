// Room: /d/xiangyang/juyilianwu2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "练功场");
	set("long", @LONG
这里是聚义馆中用来练功的地方。有几个人正在专心致致地练武，有
几个手持兵器，在互相拆招。身法灵动，犹如穿花蝴蝶一般，你不禁看花
了眼，别的人则坐在地上的蒲团上苦练内力。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east" : __DIR__"juyiyuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 1,
	]));
	setup();
	replace_program(ROOM);
}

