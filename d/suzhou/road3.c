// Room: /d/suzhou/road3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆
而过。大道两旁有一些小货摊，似乎是一处集市。东面就是苏州城了。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : __DIR__"road4",
		"east"  : __DIR__"road2",
	]));
	setup();
	replace_program(ROOM);
}

