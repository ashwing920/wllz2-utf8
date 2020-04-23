// File(/data/room/avhot/xiaoyuan.c) of avhot's room
// Create by LUBAN which written by Robert

#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short","前院");
	set ("long", @LONG
这是一所十分别致的院子，院中种满了各式各样的名贵花草，争先斗艳，十分美丽。院子旁边有一口井，井水清澈见底，十分凉爽。院子
虽然不是很大，但打扫的十分干净。
LONG
);
	set("item_desc", ([
		"paizi"   : "天上人间 - 东京热\n",
	]));

	set("key", "key of avhot");
	set("owner", "东京热");
	set("exits", ([
		"out" : "/d/room/road_e",
		"north" : __DIR__"room1",
	]));
	set("playerhouse",1);
	set("resource/water", 1);
	set("outdoors","playerroom");
	set("valid_startroom", 1);
	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
}
