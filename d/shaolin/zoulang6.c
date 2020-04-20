// Room: /d/shaolin/zoulang6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是禅房走廊。走廊南侧的房顶倚着南面的高墙，另一侧则与北边
和尚院的屋顶相连。南面墙上挂了一付对联：“悟彻菩提真妙理，断魔归
本合元神”。往北通向和尚院。
LONG
);
	set("exits", ([
		"west" : __DIR__"zoulang5",
		"east" : __DIR__"fzlou",
		"north" : __DIR__"hsyuan4",
		"south" : __DIR__"wuchang1",
	]));
	setup();
	replace_program(ROOM);
}

