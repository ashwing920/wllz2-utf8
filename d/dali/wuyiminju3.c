//Room: /d/dali/wuyiminju3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","乌夷民居");
	set("long",@LONG
这是一所乌夷族的房屋。此间正处市镇，四周无山势可依，门口正对
巷陌。青石大房，装修颇为不俗，大门是精心雕制的，刻有日、月、虎豹
等精美的图案，看来这里是乌撒部的祭祀大屋。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"enter"  : __DIR__"jisidawu1",
		"east"   : __DIR__"zhenxiong",
	]));
	setup();
	replace_program(ROOM);
}

