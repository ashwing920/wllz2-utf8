// Room: /d/xiangyang/guofuhuayuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "郭府后花园");
	set("long", @LONG
这里是郭府的后花园，园内假山林立，西边种着一些青竹，东边是几
棵枝叶茂盛的木笔花树。你一走进来，就闻到一阵阵清新的、淡淡的花香。
LONG
);
	set("exits", ([
		"east"  : __DIR__"guofuwoshi",
		"west"  : __DIR__"guofukefang",
		"south" : __DIR__"guofuting",
		"north" : __DIR__"guofushufang",
	]));
	set("objects", ([
		__DIR__"npc/huang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

