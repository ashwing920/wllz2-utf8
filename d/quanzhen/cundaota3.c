// cundaota3.c 存道塔三层
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "存道塔三层");
	set("long", @LONG
这里是存道塔的三层，塔梯绕着塔内向塔顶延伸。这里空空如也，经
书也许全被全真弟子们借去阅读了。
LONG
);
	set("exits", ([
		"westup" : __DIR__"cundaota4",
		"westdown" : __DIR__"cundaota2",
	]));
	setup();
	replace_program(ROOM);
}
