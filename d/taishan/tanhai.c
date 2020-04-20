// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "探海石");
	set("long", @LONG
这是一块从山崖向横突出的巨石，长约二丈余，向东直指渤海。巨石
三面无所凭依，视野广阔，但除非有绝高胆色的人，普通人一般都不敢攀
登这块探海石。
LONG
);
	set("exits", ([
		"westdown" : __DIR__"riguan",
		"east" : __DIR__"dongtian",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

