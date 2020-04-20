// beijie.c 北街
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
北街是武功镇最繁华的街道，每逢初一十五，还要在这里举行些庙会
之类的聚会。街北面是一家酒楼，楼前挂着一条蓝幅，上面写了个大大的
‘酒’字。西面是一户人家。几个小孩在街上笑着闹着互相追逐。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"south" : __DIR__"zhongxin",
		"north" : __DIR__"jiulou1",
		"west" : __DIR__"minju1",
	]));
	set("objects", ([
		__DIR__"npc/kid" : 3,
	]));

	setup();
	replace_program(ROOM);
}
