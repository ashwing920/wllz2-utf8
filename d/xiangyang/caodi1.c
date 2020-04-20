// Room: /d/xiangyang/caodi1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进城了，蒙古
兵驰骋来去，以为牧场，尘土飞扬，甚是嚣张。
LONG
);
	set("outdoors", "xiangyang");

	set("exits", ([
		"west"  : __DIR__"northgate2",
	]));
	set("objects", ([
		__DIR__"npc/tuolei"   : 1,
		__DIR__"npc/menggubing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

