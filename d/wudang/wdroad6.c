//Room: wdroad6.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是陕西境内的一条静悄悄的黄土路，两旁有些小土屋，疏疏落落
的。路上行人很少，都行色匆匆地向前赶路。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"south"	: __DIR__"house",
		"southeast"  : __DIR__"wdroad5",
		"west"	 : __DIR__"wdroad7",
	]));
	setup();
	replace_program(ROOM);
}
