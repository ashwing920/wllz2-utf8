// Room: /d/shaolin/woshi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
卧房里只有一张竹制的矮床上面铺了半破烂的篾席。席子上的一角耷
拉到地上。席腿边有一把断了的单刀。地上斑斑点点似乎是好多天前留下
的血迹。
LONG
);
	set("exits", ([
		"south" : __DIR__"xiaowu",
	]));
	setup();
	replace_program(ROOM);
}

