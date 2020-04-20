// jiaowai11.c
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
		"east"   : __DIR__"jiaowai10",
		"north"  : __DIR__"jiaowai13",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 2,
		"/clone/misc/shitou": 1,
	]));
	setup();
	replace_program(ROOM);
}
