//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/road2.c

inherit ROOM;

void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂密
，多产毒虫，各位行路要十分小心。
LONG
);
	set("objects", ([
		__DIR__"obj/hua1": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([
		"west"  : __DIR__"road1",
		"east"  : __DIR__"road3",
	]));
	setup();
	replace_program(ROOM);
}

