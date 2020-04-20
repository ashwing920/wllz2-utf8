//Room: /d/dali/nongtian3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","农田");
	set("long",@LONG
这里已经是平原的尽头，对面就是险峻的山岭了，一些的农田和罗伽
部村民的房屋零星地分布在山脚下，一些村民正在田里耕作。有条道路向
东南的山上蜿蜒而去。
LONG
);
	set("objects", ([
		__DIR__"npc/nongfu2": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"west"	  : __DIR__"nongtian2",
		"southeast" : __DIR__"shanlu7",
	]));
	setup();
	replace_program(ROOM);
}

