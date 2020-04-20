// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: road2.c

inherit ROOM;

void create()
{
	set("short","青石大道");
	set("long",@LONG
这是一条通往成都的大青石道，两旁绿树荫蔽，空气十分清新。成都
平原向称天府之国，四野鸡鸣犬吠，交替起落，一派安乐气息。西面隐隐
可以看到成都城门了。
LONG
);
	set("outdoors","chengdu");
	set("exits",([
		"southeast"  : __DIR__"road1",
		"west"	   : __DIR__"fuheqiaoe",
	]));
	
	setup();
	replace_program(ROOM);
}

