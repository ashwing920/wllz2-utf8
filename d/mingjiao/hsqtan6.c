//HSQTAN6.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "深潭");
	set("long", @LONG
这里的水只有齐腰深，但站在水中，仍感觉寒意从脚下漫起，经久不
散。
LONG
);
	set("exits", ([
		"up"   : __DIR__"hsqmen",
		"west" : __DIR__"hsqtan5",
	]));
	setup();
	replace_program(ROOM);
}

