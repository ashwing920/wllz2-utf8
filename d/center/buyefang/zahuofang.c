// zahuofang.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","杂货房");
	set("long",@LONG
这里是不夜舫堆放杂物和粮食的杂货房。只见杂货房里，大米一包包
的堆积如山，西边靠边的墙角，堆放着一些柴火。杂货房里光线昏暗，还
是赶快离开吧。
LONG
);
	set("exits",([
		"east": __DIR__"chufang",
	]));
	setup();
}