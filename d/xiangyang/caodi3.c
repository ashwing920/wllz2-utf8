// Room: /d/xiangyang/caodi3.c
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
		"south"  : __DIR__"northgate2",
		"north"  : "/d/city4/hanguguan",
	]));
	set("objects", ([
		__DIR__"npc/menggubing" : 2,
	]));
	setup();
	replace_program(ROOM);
}

