// Room: /d/shaolin/zoulang7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是禅房走廊。走廊南侧的房顶倚着南面的高墙，另一侧则与北边
和尚院的屋顶相连。南面墙上挂了一付对联：“灵根孕育源流出，心性修
持大道生”。往北通向和尚院。
LONG
);
	set("exits", ([
		"east" : __DIR__"zoulang8",
		"west" : __DIR__"fzlou",
		"north" : __DIR__"hsyuan1",
		"south" : __DIR__"wuchang2",
	]));
	setup();
	replace_program(ROOM);
}

