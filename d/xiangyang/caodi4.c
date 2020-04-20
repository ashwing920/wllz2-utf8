// Room: /d/xiangyang/caodi4.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进城了，这里
几十里都没了人烟。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"west"  : __DIR__"southgate2",
	]));
	setup();
	replace_program(ROOM);
}

