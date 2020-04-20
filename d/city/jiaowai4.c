// jiaowai4.c
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
		"north"	 : __DIR__"jiaowai3",
		"west"	  : __DIR__"jiaowai5",
		"southeast" : "/d/guiyun/shulin1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/zhao-gouer" : 1,
		"/clone/misc/shuzhi": 2,
		"/clone/misc/shitou": 2,
	]));

	setup();
	replace_program(ROOM);
}

