// yongdao1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
你慢慢爬了进去，见是这里是一条狭窄的天生甬道，其实是山腹内的
一条裂缝，爬了十多丈远，甬道渐高，再前进丈余，已可站直。你挺一挺
腰，向前走去。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"out"  : __DIR__"shanbi",
		"east" : __DIR__"yongdao2",
	]));
	setup();
	replace_program(ROOM);
}

