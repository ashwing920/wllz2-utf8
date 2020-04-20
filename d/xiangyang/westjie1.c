// Room: /d/xiangyang/westjie1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西边是一个大十字街
口。东面是襄阳的中央广场，北边是人称郭大侠郭靖的府邸大门，不时地
有人从那里进进出出。南面是一家当铺，听说里面常能买到你所需的东西。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"guangchang",
		"west"  : __DIR__"westjie2",
		"south" : __DIR__"dangpu",
		"north" : __DIR__"guofugate",
	]));
	set("objects", ([
		__DIR__"npc/poorman" : 1,
	]));
	setup();
	replace_program(ROOM);
}

