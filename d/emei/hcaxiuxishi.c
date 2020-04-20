//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: hcaxiuxishi.c 华藏庵休息室

#include <room.h>

inherit ROOM;

void create()
{
	set("short","华藏庵休息室");
	set("long",@LONG
这里是峨嵋华藏庵的休息室。窗帘拉下来，房里整整齐齐放了很多木
床。有几个夜晚守庵的小师太正在睡觉，休息室外就是禅房。
LONG);
	set("exits",([
		"north" : __DIR__"hcachanfang", 
	]));
	set("sleep_room", 1);

	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
