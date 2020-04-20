// Room: daobu.c 刀刃部
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "刀刃部");
	set("long", @LONG
这是武馆的刀刃部，由龙铨负责。四周都是木片木人，可供练习。
LONG
);

	set("exits", ([
		"south" : __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/longquan" : 1,
	]));
	setup();
	replace_program(ROOM);
}
