// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: road1.c

inherit ROOM;

void create()
{
	set("short","青石大道");
	set("long",@LONG
这是一条通往成都的大青石道，两旁绿树荫蔽，空气十分清新。成都
平原向称天府之国，这里四周田野稻浪滚滚，平平展展的大地上，偶尔会
出现一大丛翠竹浓荫，细细认去，都是人家居处。
LONG
);
	set("outdoors","chengdu");
	set("exits",([
		"east"	   : "/d/emei/qsjie1",
		"northwest"  : __DIR__"road2",
	]));
	
	setup();
	replace_program(ROOM);
}

