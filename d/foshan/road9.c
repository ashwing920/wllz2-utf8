//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/road9.c

inherit ROOM;

void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。岭南山林茂密，多产毒虫，各
位行路要十分小心。
LONG
);
	set("objects", ([
		__DIR__"obj/hua2": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([
		"west" : __DIR__"road8",
		"east" : __DIR__"road10",
	]));
	setup();
	replace_program(ROOM);
}

