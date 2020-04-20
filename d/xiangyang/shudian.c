// Room: /d/xiangyang/shudian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "书店");
	set("long", @LONG
这里的老板刚从南阳搬来，听说以前他曾在嵩山少林寺出过家，后不
知什么原因又还了俗，专门卖书为生。只见书店面积很大，以前曾是一座
勾栏。
LONG
);
	set("exits", ([
		"east" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/shudianboss" : 1,
	]));
	setup();
	replace_program(ROOM);
}
