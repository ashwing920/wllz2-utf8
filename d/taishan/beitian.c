// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "北天门");
	set("long", @LONG
这里位于石马山的北麓，是岱顶的北面出口，路口有一石坊，上面写
着「玄武」二字。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

