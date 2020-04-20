// shanlu2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
走在这条不是很宽的山路上，只见两旁峰峦秀丽，景色怡人。一条小
溪在路边潺潺流过，溪畔有一农家。山村小景，使人有退隐江湖之意。南
上便到了中天竺。北下就是下天竺。
LONG
);
	set("exits", ([
		"southup"   : __DIR__"fajinsi",
		"northdown" : __DIR__"fajingsi",
	]));
	set("objects", ([
		__DIR__"npc/honghua2" : 2,
	]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}

