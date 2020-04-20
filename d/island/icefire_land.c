//Cracked by Kafei
// kane: 98/3/025

inherit ROOM;

void create()
{
	set("short", "冰火岛");
	set("long", @LONG
这是岛屿东部的一个大平原，远处高山玄冰白雪，平野上却极目青绿
，苍松翠柏，高大异常，更有诸般奇花异树，皆为中土所无。平野上一群
梅花鹿正幽闲的吃草，毫不惧人。
LONG
);
	set("exits", ([
		"west" : __DIR__"icefire1",
	]));
	set("objects", ([
                __DIR__"npc/deer": 3,
	]) );
	set("outdoors", "island");
	setup();
	replace_program(ROOM);
}

