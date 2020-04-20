// Room: jianbu.c 剑部
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "剑部");
	set("long", @LONG
这是武馆的剑部，由刘虹瑛负责。到处摆着竹筒木人，可供练习。
LONG
);

	set("exits", ([
		"north" : __DIR__"zoulang2",
	]));

	set("objects", ([
		__DIR__"npc/liuhongying" : 1,
	]));
	setup();
	replace_program(ROOM);
}
