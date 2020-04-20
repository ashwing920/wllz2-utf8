// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","走廊");
	set("long", @LONG
这是一条通向黑蝎堂的走廊，光线十分昏暗，静悄悄的没有一点声音。
LONG
);
	set("exits", ([
		"west" : __DIR__"heixietang",
		"southeast" :__DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}



	