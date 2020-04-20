//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: fsaxiuxishi.c 福寿庵休息室

#include <room.h>

inherit ROOM;

void create()
{
	set("short","福寿庵休息室");
	set("long",@LONG
这是福寿庵接待峨嵋女侠们的休息室，峨嵋女弟子回山之前通常在此
借宿一宿，好备足体力上山。房内摆有一张长桌，靠墙设有几张木床。
LONG
);
	set("exits",([
		"southdown" : __DIR__"fsazhaitang",
	]));
	create_door("southdown", "门", "northup", DOOR_CLOSED);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
