// guanwai/milin3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
这是一片茂密的松林，杂乱的生长在倾斜的山坡上。每棵松树都有三
四抱粗细，高达十几丈。树冠枝多叶密，将天空完全遮住，因此林内显得
有些昏暗。树木之间长着很多灌木杂草，使行走很艰难，据说人参就生长
在这些杂草之中。
LONG
);
	set("exits", ([
		"northdown"  : __DIR__"milin2",
		"eastup" : __DIR__"heifengkou",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
