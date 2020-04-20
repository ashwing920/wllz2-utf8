// shanlu3.c 山路
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
前面好象有一个大山谷，走到这里，树木多了些，全都是柏树。西面
是一条弯曲的山路，隐藏在山间，要在夜里还真看不出来。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"southwest" : __DIR__"shanlu2",
		"northup" : __DIR__"cuipinggu",
	]));
	setup();
	replace_program(ROOM);
}
