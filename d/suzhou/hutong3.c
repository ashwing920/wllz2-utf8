// Room: /d/suzhou/hutong3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，几
个流氓在游荡，向东南就能回到大街，你还是赶快走吧。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"west"	  : __DIR__"hutong2",
		"southeast" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 2,
	]));
	setup();
	replace_program(ROOM);
}

