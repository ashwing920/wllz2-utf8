// Room: /d/suzhou/yunhematou.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "运河码头");
	set("long", @LONG
这里是运河码头。它是朝廷漕运要塞，水陆必经之处。运河中来往船
只满载穿梭，极其繁忙。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"southeast" : __DIR__"xidajie1",
	]));
	setup();
	replace_program(ROOM);
}

