//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/road5.c

inherit ROOM;

void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂密
，多产毒虫，各位行路要十分小心。
LONG
);
	set("outdoors","foshan");
	set("exits",([ 
		"east"	  : __DIR__"road6",
		"northwest" : __DIR__"road4",
	]));

	setup();
	replace_program(ROOM);
}

