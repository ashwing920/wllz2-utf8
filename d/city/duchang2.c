// duchang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里有四条走廊通向不同的房间。四周是拱猪小屋。
LONG );
	set("exits", ([
		"east"  : "/inherit/room/eproom",
		"west"  : "/inherit/room/wproom",
		"south" : "/inherit/room/sproom",
		"north" : "/inherit/room/nproom",
		"down"  : __DIR__"duchang",
	]));

	setup();
	replace_program(ROOM);
}
