//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西四北大街");
	set("long", @LONG
这是一条长长的街道。东边就是游人们常去的文庙，那里长年香火不
断，烟雾缭绕。南边是西单。
LONG );
	set("outdoors", "city2");
	set("exits", ([
		"north" : __DIR__"xisi2",
		"east" : __DIR__"wenmiao",
		"south" : __DIR__"xidan",
	]));

	setup();
	replace_program(ROOM);
}


