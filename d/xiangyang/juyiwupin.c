// Room: /d/xiangyang/juyiwupin.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "物品房");
	set("long", @LONG
这是聚义馆的堆放各种各样物品的房间。郭靖的二弟子武修文正在这
儿负责向有任务的新手分发各种物品。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"juyihuayuan",
	]));
	set("objects", ([
		__DIR__"npc/wuxiuwen" : 1,
	]));
	setup();
	replace_program(ROOM);
}

