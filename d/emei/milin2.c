//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: milin2.c 密林

inherit ROOM;

void create()
{
	set("short","密林");
	set("long",@LONG
这是黑森森的一片密林，楠木参天，浓阴蔽日。这里西上是报国寺，
东边林间隐藏着一座庙宇。
LONG
);
	set("exits",([ 
		"eastdown"  : __DIR__"fhs",
		"westup"	: __DIR__"jietuopo",
	]));
	set("outdoors", "emei");

	setup();
	replace_program(ROOM);
}
