// Room: /t/wanjiegu/shan_road4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条山间小路，两边山坡上张了许多树木，北风吹过，发出沙沙
的响声。路上张着许多杂草，看起来这里很少有人走动。往西看，远远可
见黑压压一片大森林。
LONG
);
	set("outdoors", "wanjiegu");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"entrance",
		"southup" : __DIR__"shan_road3",
	]));
	setup();
	replace_program(ROOM);
}
