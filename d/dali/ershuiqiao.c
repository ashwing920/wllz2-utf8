//Room: /d/dali/ershuiqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","洱水桥");
	set("long",@LONG
一座长百余步的青石桥。此桥横跨洱水，连接下关城和大理城，桥下
清澈的洱水滚滚东去。桥北正是下关城的城门，桥南一路南行十数里即可
到大理城。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"xiaguan",
		"southeast"  : __DIR__"dalinorth",
	]));
	setup();
	replace_program(ROOM);
}

