// Room: /d/fuzhou/dongdajie.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
街道两侧，榕木参天。福州盛夏苦热，广植榕树以纳凉爽，别名“榕
城”。北面是客店，南面通往山上。
LONG
);
	set("exits", ([
		"southup" : __DIR__"yushan",
		"north"   : __DIR__"rongcheng",
		"east"	: __DIR__"dongxiaojie",
		"west"	: __DIR__"dongjiekou",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

