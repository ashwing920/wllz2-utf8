// Room: /d/xiangyang/juyihuayuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
这是聚义馆的大花园。园内种着各种各样的花草，清风吹来，你能闻
到股股花香。园内东西两侧各有一排厢房，北面是一湖池水，水上架着走
廊，直通西大街。南面是馆内厨房，东南方向有一间物品房。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"	  : __DIR__"juyifemale",
		"west"	  : __DIR__"juyimale",
		"south"	 : __DIR__"juyichufang",
		"north"	 : __DIR__"juyilang",
		"southeast" : __DIR__"juyiwupin",
	]));
	set("objects", ([
		__DIR__"npc/guofu" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("gender") != "男性" && dir == "west") 
		return notify_fail("男女有别，请到对面住！\n");

	if (me->query("gender") != "女性" && dir == "east") 
		return notify_fail("男女有别，请到对面住！\n");

	return ::valid_leave(me, dir);
}
