// Room: /d/hengshan/cuiping1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "翠屏山道");
	set("long", @LONG
你爬在翠屏山道上，石阶陡峭，近在目前。回头外望，恒山重峦叠嶂
，林木幽深，倍感静谧。
LONG
);
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"	: __DIR__"cuipinggu2",
	]));
	set("outdoors", "hengshan");
	setup();
	replace_program(ROOM);
}

