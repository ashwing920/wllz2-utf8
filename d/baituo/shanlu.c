//shanlu.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
这里是山上的泥路。
LONG
);
	set("exits",([
		"northwest" : __DIR__"shanlu1",
		"southeast" : __DIR__"guangchang",
	]));
	set("outdoors", "baituo");

	setup();
	replace_program(ROOM);
}

