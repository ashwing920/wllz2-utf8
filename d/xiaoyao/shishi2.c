// shishi2.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一个石头砌成的房间，因为好久没有人来过，散发着一些很难闻
的气味，房间中到处可以看到蛛丝和虫迹。
LONG
);
	set("exits", ([
		"north" : __DIR__"shiji3",
		"west" : __DIR__"shiji2",
	]));
	create_door("north", "石门", "south", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
