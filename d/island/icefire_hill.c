//Cracked by Kafei
// kane: 98/3/025

inherit ROOM;

void create()
{
	set("short", "冰火岛");
	set("long", @LONG
这是冰火岛西部的山峰地带，奇形怪状的山峰随处可见，且遍地燧石
。此处大概是火山溶岩喷发后，凝结而成，因而形状如此诡异。再往前走
就是一座正冒着烟的火山了。
LONG
	);
	set("exits", ([
		"east" : __DIR__"icefire1",
	]));
	set("outdoors", "island");
	setup();
	replace_program(ROOM);
}

