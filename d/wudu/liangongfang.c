// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  "练功房" );
	set("long", @LONG
这是一间练功房，出了几个供练功的木蜘蛛以外，别无他物几个弟子
正在专心致至的和蜘蛛人比划着。
LONG
);
        set("exits", ([
		"north" : __DIR__"zoulang",
	]));
	set("objects", ([
		__DIR__"npc/zhizhuren" : 5,
	]));
	setup();
	replace_program(ROOM);
}



	