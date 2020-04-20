// Room: /huanghe/tiandi4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "田地");
	set("long", @LONG
这里是一大片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围是
一块块的田地，田里有一些正在耕作的农人。村里不时传出一声声的犬吠。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"tiandi3",
		"north"	 : __DIR__"huanghe1",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

