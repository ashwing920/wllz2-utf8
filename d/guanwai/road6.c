//guanwai/road6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你走在一条碎石铺成的大道上，道两旁种着笔直通天的白杨树，放眼
向两侧望去，全是无边无际的田野，天边处仿佛有几座低矮的丘陵，为平
坦的大地增加了几许柔和的曲线。路上渐渐的出现了一些积雪。
LONG
);
	set("exits", ([
		"north" : __DIR__"road7",
		"south" : __DIR__"road5",
	]));
	set("objects",([
		__DIR__"npc/sanhu" : 1,
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

