// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","密道");
	set("long", @LONG
一条十分隐蔽的密道，不过墙壁上却点着油灯，看来经常有人出入。
LONG
);
	set("exits", ([
		"east" : __DIR__"midao1",
		"west" : __DIR__"midao3",
	]));
	setup();
	replace_program(ROOM);
}

