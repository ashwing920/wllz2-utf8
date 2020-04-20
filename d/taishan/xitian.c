// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西天门");
	set("long", @LONG
这里有两块巨石壁立，有如给人斩削过似的，正是岱顶的西面出口。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

