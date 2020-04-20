//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: milin1.c 密林

inherit ROOM;

void create()
{
	set("short","密林");
	set("long",@LONG
这是黑森森的一片密林，楠木参天，浓阴蔽日。这里东下二里是报国
寺，西边林间隐藏着一座庙宇。
LONG
);
	set("exits",([ 
		"northeast"  : __DIR__"bgs",
		"west"	   : __DIR__"fhs",
	]));
	set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}
