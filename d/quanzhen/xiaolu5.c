// xiaolu5.c 后山小路
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这里是后山上的小路。这条小路好象不是人工刻意修出来的，也许只
是以前的采药人踩多了，现出这样一条小路来。走到这里，你好象迷路了。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"east" : __DIR__"xiaolu9",
		"west" : __FILE__,
		"north" : __DIR__"xiaolu6",
		"south" : __DIR__"xiaolu3",
	]));
	setup();
	replace_program(ROOM);
}

