// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: eastroad3.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。向北是一条宽直的大道。
北边可以通往东城门，西南边通向南大街，东南方就是有名的望江楼了。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"southeast"  : __DIR__"wangjianglou",
		"southwest"  : __DIR__"southroad1",
		"north"	  : __DIR__"eastroad2",
	]));
	setup();
	replace_program(ROOM);
}
