// Room: /d/xiangyang/westjie2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这儿是很大的十字街口，北边是西内大街，南面是一座彩楼，楼前高
高的挂着一方大匾，上面用正楷写着“聚义馆”，落款“朱子柳”。东边
通向中央广场，西面可达白虎门。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"westjie1",
		"west"  : __DIR__"westjie3",
		"south" : __DIR__"juyiyuan",
		"north" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wusantong" : 1,
	]));
	setup();
	replace_program(ROOM);
}

