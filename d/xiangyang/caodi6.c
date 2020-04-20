// Room: /d/xiangyang/caodi3.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进城了，虽然
蒙古兵没来到南门，但肃杀氛围丝毫不减。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"north"  : __DIR__"southgate2",
		"south"  : "/d/wudang/wdroad5",
	]));
	setup();
	replace_program(ROOM);
}

