// milin.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "青竹林");
	set("long", @LONG
这是一片茂密的青竹林，一走进来，你仿佛迷失了方向。
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"ml4",
		"south" : __DIR__"dongmen",
		"north" : __FILE__,
	]));

	setup();
	replace_program(ROOM);
}