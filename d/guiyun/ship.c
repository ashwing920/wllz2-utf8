// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /guiyun/ship.c

inherit ROOM;

void create()
{
	set("short", "战船");
	set("long", @LONG
这是一艘大渔船，船上的人白天打鱼，晚上就干些没本钱的买卖，接
济沿湖的百姓。
LONG
);
	set("outdoors", "guiyun");
	set("objects", ([
		__DIR__"npc/haojie" : 1,
	]));
	setup();
	replace_program(ROOM);
}
