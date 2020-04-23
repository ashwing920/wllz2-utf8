// File(/data/room/abcd/xiaoyuan.c) of abcd's room
// Create by LUBAN which written by Robert

#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short","小院");
	set ("long", @LONG
这是一所十分别致的小院。只见小院之中种满了各式各样的花草，十分亮丽。蝴蝶，蜻蜓在花丛中不停的飞舞，一片生机勃勃的景象。
LONG
);
	set("item_desc", ([
		"paizi"   : "测试 - 新闻官\n",
	]));

	set("key", "key of abcd");
	set("owner", "新闻官");
	set("room_owner_id","abcd");
	set("exits", ([
		"out" : "/d/room/road_e",
		"north" : __DIR__"room1",
	]));
	set("playerhouse",1);
	set("outdoors","playerroom");
	set("valid_startroom", 1);
	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
}
