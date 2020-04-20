// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short","小路");
	set("long", @LONG
这是一条人迹罕至的小路，两边杂草从生，西面有几间草房看上去是
一家农户，可又十分古怪，透着些蹊跷。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"west" :__DIR__"caofang",
		"east" : __DIR__"xiaolu",
	]));
	setup();
	replace_program(ROOM);

}

