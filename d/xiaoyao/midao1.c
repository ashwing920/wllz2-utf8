// midao1.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "秘密通道");
	set("long", @LONG
这是一段又长又黑的秘密通道，隐约可以感觉到四周是冰冷而坚硬的
石壁，你什么了看不清楚，只可以靠摸索着前进。
LONG
);
	set("exits", ([
		"out" : __DIR__"shishi3",
		"north" : __DIR__"midao2",
	]));

	setup();
	replace_program(ROOM);
}
