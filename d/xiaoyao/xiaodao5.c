// xiaodao5.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条从南到北的林间小道，沿途风景极之清幽，参天古树，拔地
而起，两旁百花争艳。令人留连忘返。
LONG
);
	set("exits", ([
		"south" : __DIR__"muwu1",
		"north" : __DIR__"qingcaop",
	]));

	set("outdoors", "xiaoyao");
	setup();
	replace_program(ROOM);
}
