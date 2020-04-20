// Room: /d/shaolin/zoulang8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是禅房走廊。走廊南侧的房顶倚着南面的高墙，另一侧凌空架在
几根细细的石柱上，倚在栏杆上，北望是一大片竹林，馨香满怀，竹影摇
曳，诗意顿上心头，别有一番韵趣。
LONG
);
	set("exits", ([
		"west" : __DIR__"zoulang7",
		"north" : __DIR__"zhulin1",
		"southdown" : __DIR__"luohan9",
	]));
	setup();
	replace_program(ROOM);
}

