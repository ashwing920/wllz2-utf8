// Room: /huanghe/tiandi1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "田地");
	set("long", @LONG
这里林木渐渐稀疏，不远处有一些村庄，炊烟袅袅升起。村庄周围是
一块块的田地，田里有一些正在耕作的农人。
LONG
);
	set("exits", ([
		"south" : __DIR__"shulin3",
		"west"  : __DIR__"tiandi2",
		"east"  : __DIR__"tiandi3",
	]));
	set("objects", ([
		"/d/village/npc/poorman" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

