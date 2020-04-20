//Room: /d/dali/wuyiminju2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","乌夷民居");
	set("long",@LONG
这是一所乌夷族的房屋。乌夷民居的建地和走向讲究依傍四面山势，
一般以石为墙和基，以木为梁，结构大致和汉人房屋相仿，皆是平房，石
砌围墙。这家院内有一排木架，挂了些山鸡、野鸭、羚羊等猎物，一个猎
人正在给猎物剥皮开膛。
LONG
);
	set("objects", ([
		__DIR__"npc/lieren": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"wumeng",
	]));
	setup();
	replace_program(ROOM);
}

