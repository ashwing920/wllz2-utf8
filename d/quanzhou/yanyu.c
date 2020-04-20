// Room: /d/quanzhou/yanyu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "烟雨楼");
	set("long", @LONG
烟雨楼建在南湖中心的一个小岛上。南湖终年不断的水气把它笼罩得
迷迷蒙蒙的。楼内是家饭店。店内正在装修楼梯。请勿上楼。
LONG
);
	set("exits", ([
		"up"	: __DIR__"yanyu2",
		"north" : __DIR__ "nanhu1",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1
	]));

	setup();
	replace_program(ROOM);
}

