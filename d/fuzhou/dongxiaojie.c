// Room: /d/fuzhou/dongxiaojie.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "东小恐");
	set("long", @LONG
街道两侧，榕木参天。福州盛夏苦热，广植榕树以纳凉爽，别名“榕
城”。东面就出城了，西面是城中心。
LONG
);
	set("exits", ([
		"east"	: __DIR__"dongmen",
		"west"	: __DIR__"dongdajie",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

