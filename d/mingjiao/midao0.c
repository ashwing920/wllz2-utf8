// Room: /d/mingjiao/midao0.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
#include <room.h>;
void create()
{
	set("short", "甬道");
	set("long", @LONG
这是一条小小的甬道，周围都是石壁，极为坚硬，看来不是什么武功
能打破的。向外的石门早已悄然合上，你只有鼓勇向前。
LONG
);
	set("exits", ([
		"north" : __DIR__"midao1",
	]));
	setup();
	create_door("north", "石门", "south", !DOOR_CLOSED);
	replace_program(ROOM);
}
