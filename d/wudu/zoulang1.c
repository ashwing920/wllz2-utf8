// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long", @LONG
这是一条通向金蛇堂的走廊，光线十分昏暗，静悄悄的没有一点声音。
LONG
);
	set("exits", ([
		"north" : __DIR__"jinshetang",
		"south" :__DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}



	