// Room: /d/huashan/jzroad7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "峭壁");
	set("long", @LONG
你走在峭壁边的小路上。一侧是密密的丛林，外侧却是极深的陡壁。
山风凛冽，几乎要把你刮落崖去。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown" : __DIR__"jzroad6",
		"southup"  : __DIR__"shangu",
	]));
	set("outdoors", "xx");
	setup();
	replace_program(ROOM);
}

