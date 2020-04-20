// Room: /d/henshan/shiziyan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "狮子岩");
	set("long", @LONG
狮子岩布满奇形怪状的岩石，细究则绝类狮子，腾跃伏吼，各肖其类
。到狮子岩，祝融峰已经在望了。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southwest"  : __DIR__"nantian",
		"northup"	: __DIR__"wangritai",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

