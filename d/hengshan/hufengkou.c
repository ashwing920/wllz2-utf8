// Room: /d/hengshan/hufengkou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "虎风口");
	set("long", @LONG
过步云桥，望仙亭，就到了一个峰回路转的陡峭路口，这里是一处风
口，大风来处，声如虎啸，比别处强劲多多，故有是名。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"daziling",
		"west"	  : __DIR__"xuangengsong",
		"northeast" : __DIR__"guolaoling",
	]));
	set("outdoors", "hengshan");

	setup();
	replace_program(ROOM);
}

