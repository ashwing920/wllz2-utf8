// Room: /d/xiangyang/westroad1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西内大街");
	set("long", @LONG
这是一条青石铺就的大街。隐隐地能望见南面是一座很高的彩楼，东
面是一堵盖着红色琉璃瓦的高墙，里面是郭府大院。西面是襄阳城老字号
的客店，北面是青石铺的大街。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"west"  : __DIR__"kedian",
		"south" : __DIR__"westjie2",
		"north" : __DIR__"westroad2",
	]));
	setup();
	replace_program(ROOM);
}

