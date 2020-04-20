// jiaowai13.c
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
		"south" : __DIR__"jiaowai11",
		"east"  : __DIR__"jiaowai12",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/mo-bu" : 1,
		"/clone/misc/shuzhi": 1,
	]));
	setup();
	replace_program(ROOM);
}