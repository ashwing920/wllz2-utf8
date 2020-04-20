// Room: /d/henshan/houdian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "后殿");
	set("long", @LONG
后殿是南岳大庙的第八进，也是南岳大帝的寝宫。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"dadian",
		"north"  : __DIR__"beimen",
	]));
	setup();
	replace_program(ROOM);
}

