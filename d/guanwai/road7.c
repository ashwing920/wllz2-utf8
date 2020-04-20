//guanwai/road7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条碎石铺成的大道上，道两旁种着笔直通天的白杨树，放眼
向两侧望去，全是无边无际的田野，天边处仿佛有几座低矮的丘陵，为平
坦的大地增加了几许柔和的曲线。呼啸而过的狂风冻得人直打哆嗦。
LONG
);
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : __DIR__"road6",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

