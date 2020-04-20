// Room: /d/suzhou/hutong2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，几
个贼眉鼠眼地盯着你的腰包，看来会马上扑上来。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"east"	  : __DIR__"hutong3",
		"southwest" : __DIR__"hutong1",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" : 2,
	]));
	setup();
	replace_program(ROOM);
}

