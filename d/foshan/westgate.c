//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/westgate.c

inherit ROOM;

void create()
{
	set("short","佛山西门");
	set("long",@LONG
这里是佛山镇的西门。岭南以西经由广西可至大理。东面一条东西向
的大街是佛山镇的主要街道。
LONG
);
	set("outdoors", "foshan");
	set("exits",([
		"east"  : __DIR__"street1",
		"west"  : __DIR__"road7",
	]));

	setup();
	replace_program(ROOM);
}

