// Room: /d/mingjiao/huangtulu1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄土小路");
	set("long", @LONG
这里是茂密松林中的一条黄土小路。松林极密，四面都是蓝幽幽的感
觉，映衬着天心雪峰，极尽凄美。
LONG
);
	set("exits", ([
		"west" : __DIR__"huangtulu2",
		"east" : __DIR__"shanlu2",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

