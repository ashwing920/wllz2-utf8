//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/street5.c

inherit ROOM;

void create()
{
	set("short","佛山镇街");
	set("long",@LONG
佛山镇街东西相连。东边是镇东门，南面一堵高墙，墙后便是凤天南
开的“英雄典当”。
LONG
);
	set("objects", ([
		__DIR__"npc/wolfdog": 1,
		__DIR__"npc/jiading": 2,
	]));
	set("outdoors", "foshan");
	set("exits",([
		"south" : __DIR__"dangpu",
		"west"  : __DIR__"street4",
		"east"  : __DIR__"eastgate",
	]));
	setup();
	replace_program(ROOM);
}

