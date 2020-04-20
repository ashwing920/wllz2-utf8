// Room: /d/songshan/shandao4.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你走在嵩山山道，青松翠柏，山风岚雾，时来飘荡。远望山下犬吠鸡
啼，顿起仙凡之感。
LONG
);
	set("exits", ([
		"northup"   : __DIR__"fawangsi",
		"southeast" : __DIR__"songyuesi",
	]));
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

