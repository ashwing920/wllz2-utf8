// Room: jianbu.c 棒杖部
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "棒杖部");
	set("long", @LONG
这是武馆的棒杖部，由陈浒负责。到处摆着木人沙包，可供练习。
LONG
);

	set("exits", ([
		"north" : __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/chenhu" : 1,
	]));
	setup();
	replace_program(ROOM);
}
