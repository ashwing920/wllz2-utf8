// Room: /t/wanjiegu/slide3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
山坡之上张着一些不知名的杂草，以及三三两两分布其间的灌木丛，
这里很少有大树，几朵野花在路边悄悄开放，偶尔有几只蝴蝶飞来飞去。
LONG
);
	set("outdoors", "wanjiegu");
	set("exits", ([ /* sizeof() == 2 */
		"southup" : __DIR__"shan_road1",
		"eastdown" : __DIR__"port2",
	]));
	setup();
	replace_program(ROOM);
}