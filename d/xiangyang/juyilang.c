// Room: /d/xiangyang/juyilang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "水上走廊");
	set("long", @LONG
这时一条笔直的走廊，廊下是一湖池水。湖水映着长长垂柳，碧绿清
澈，你能看见一些鱼在游来游去。南面就是一个大花园，圆内东西两侧各
有一排厢房。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"south" : __DIR__"juyihuayuan",
		"north" : __DIR__"juyiyuan",
	]));
	setup();
	replace_program(ROOM);
}

