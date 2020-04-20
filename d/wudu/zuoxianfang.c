// by netkill 98-9-19

inherit ROOM;

void create()
{
	set("short","左厢房");
	set("long", @LONG
这是一间厢房，一边墙上有一个大书架，中间一张方桌，靠里有张小
床，看上去虽然简陋，却显示着一种威严之气。
LONG
);
	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"jinshetang",
	]));
	set( "objects", ([
		__DIR__"obj/wuduxinfa" :1,
		__DIR__"obj/wudubianfa":1,
	]));
	setup();
	replace_program(ROOM);
}
