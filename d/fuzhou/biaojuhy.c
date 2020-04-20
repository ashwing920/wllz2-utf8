// Room: /city/biaojuhy.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "福威镖局后院");
	set("long", @LONG
镖局后院是平常镖师们打拳练功之所，除了几个木桩石锁外，别无它
物。
LONG
);
	set("exits", ([
		"south" : __DIR__"biaojuzt",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

