//Room: wdroad7.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里一条静悄悄的黄土路，两旁有些小土屋，疏疏落落的。路上行人
很少，都行色匆匆向前赶路。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"east"	: __DIR__"wdroad6",
		"southwest" : __DIR__"wdroad8",
	]));
	setup();
	replace_program(ROOM);
}


