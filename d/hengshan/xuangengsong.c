// Room: /d/hengshan/xuangengsong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "悬根松");
	set("long", @LONG
就在虎风口这个风口险地，却有一株古松，虽被大风吹得树根裸露，
千百年来仍迎风挺立，这就是恒山著名的$HIW$梵宫悬根$NOR$。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east"	  : __DIR__"hufengkou",
	]));
	set("outdoors", "hengshan");

	setup();
	replace_program(ROOM);
}

