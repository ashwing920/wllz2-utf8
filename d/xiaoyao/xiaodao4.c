// xiaodao4.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到
路的尽头。两旁百花争艳。令人留连忘返。
LONG
);
	set("exits", ([
		"east" : __DIR__"shulin_in",
		"west" : __DIR__"qingcaop",
		"north" : __DIR__"liangong",
		"south" : __DIR__"mubanlu",
	]));
	set("objects", ([
		CLASS_D("xiaoyao") + "/mengmianr": 2,
	]));
	set("outdoors", "xiaoyao");
	setup();
	replace_program(ROOM);
}
