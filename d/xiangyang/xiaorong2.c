// Room: /d/xiangyang/xiaorong2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
这里是襄阳城内老百姓的居住区。只见小弄两边是有些小店面，有米
行、小杂货铺等。一些居民从这里进进出出。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"jiekou2",
	]));
	set("objects", ([
		"/d/center/npc/boy"  : 1,
		"/d/center/npc/girl" : 1,
	]));
	setup();
	replace_program(ROOM);
}

