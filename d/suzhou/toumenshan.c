// Room: /d/suzhou/toumenshan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "头门山");
	set("long", @LONG
头山门在虎丘山的南面，形似虎头。隔河照墙上书着“海涌流辉”四
个大字，以示虎丘与大海的渊源关系。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"north" : __DIR__"huqiu",
		"west"  : __DIR__"wanjing",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	setup();
	replace_program(ROOM);
}

