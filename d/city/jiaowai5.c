// jiaowai5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
扬州郊外的茂密树林，阴森可怖。抬头不见天日。这里也是扬州命案
发生最多的地方。鸟兽蛇虫游荡不穷。
LONG );
	set("exits", ([
		"east"  : __DIR__"jiaowai4",
		"west"  : __DIR__"jiaowai6",
	]));
	set("objects", ([
		"/clone/misc/shuzhi": 2,
		__DIR__"npc/dushe" : 1,
	]));

	setup();
	replace_program(ROOM);
}

