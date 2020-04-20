// Room: /d/henshan/chidifeng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "赤帝峰");
	set("long", @LONG
相传祝融能以火施化，是黄帝的火正官，并主管南方的事务，死后葬
于此，故名赤帝峰。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southdown"  : __DIR__"shanlu2",
		"eastdown"   : __DIR__"shanlu11",
		"northdown"  : __DIR__"shanlu3",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

