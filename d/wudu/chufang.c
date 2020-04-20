// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  "厨房" );
	set("long", @LONG
一间普通的厨房，一个厨子正在忙着为弟子们做食物，不时会有弟子
来向厨师要食物，他总是笑眯眯的给大家分派。
LONG
);
	set("exits", ([
		"east" : __DIR__"qianting",
	]));
	set("objects", ([
		__DIR__"npc/chushi" : 1,
	]));
	setup();
	replace_program(ROOM);
}



	