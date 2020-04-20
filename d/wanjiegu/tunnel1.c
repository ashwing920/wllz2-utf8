// Room: /t/wanjiegu/tunnel1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
地道里光线黑暗，空气浑浊，一股霉味扑鼻而来。地道里石台阶异常
粗糙，两边土墙上不时渗出水滴掉到地上。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"tunnel2",
		"out" : __DIR__"tree_hole",
	]));
	setup();
	replace_program(ROOM);
}
