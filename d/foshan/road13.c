//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/road13.c

inherit ROOM;

void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。进入福建省境了，闽西山林茂
密，多产毒虫，各位行路要十分小心。
LONG
);
	set("objects", ([
		__DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([
		"northeast" : __DIR__"road14",
		"southwest" : __DIR__"road11",
	]));
	setup();
	replace_program(ROOM);
}

