// cangjing.c 后山门
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "后山门");
	set("long", @LONG
这是藏经阁后，东北边有扇小门。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"chmiao",
		"southup" : __DIR__"cangjing",
	]));
	create_door("northeast", "小门", "southwest", DOOR_CLOSED);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
