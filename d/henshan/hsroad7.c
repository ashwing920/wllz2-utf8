// Room: /d/henshan/hsroad7.c 林间大道
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "林间大道");
	set("long", @LONG
这里是一条林间大道，在树丛中蜿蜒。这里是湖北境内。南边是湖南。
LONG
);
	set("outdoors", "henshan");
	set("exits", ([
		"north"  : __DIR__"hsroad8",
		"south"  : __DIR__"hsroad6",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	setup();
	replace_program(ROOM);
}

