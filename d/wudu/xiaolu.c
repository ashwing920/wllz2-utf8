// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short","小路");
	set("long", @LONG
这是一条人迹罕至的小路，两边杂草从生，西面看去好象有几座房子。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"west" :__DIR__"xiaolu1",
		"east" : __DIR__"milin/exit",
	]));
	setup();
	replace_program(ROOM);

}

