// shanlu1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条被人走出来的山路，弯弯曲曲地向上延伸。走在山路上，只见两
旁峰峦秀丽，景色怡人。不时有进香客擦肩而过。南上便到了下天竺。北
下就是大道。
LONG
);
	set("exits", ([
		"southup"   : __DIR__"fajingsi",
		"northdown" : __DIR__"road2",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
