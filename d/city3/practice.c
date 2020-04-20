// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: practice

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武馆操练房");
	set("long", @LONG
这里摆满了石锁簸箕、大刀长剑、沙袋绑腿等，还有几个精心扎制的
橡皮人，是武馆弟子日常练功的地方。
LONG
);
	set("exits", ([
		"down"   : __DIR__"wuguan",
	]));

	set("objects", ([
		__DIR__"npc/xiangpi-ren" : 6,
	]));
	setup();

}


