// Room: /d/xiangyang/dingzi.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "丁字街口");
	set("long", @LONG
这里是襄阳城北部的丁字街口。向北一直通向玄武门，东面和西面是
一条笔直的青石大街，通向城内。南面是一堵上盖红色琉璃瓦的高墙，里
面是襄阳安抚使吕文德的府邸。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"northroad2",
		"west"  : __DIR__"northroad1",
		"north" : __DIR__"northjie",
	]));
	setup();
	replace_program(ROOM);
}

