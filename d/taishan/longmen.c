// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "龙门");
	set("long", @LONG
这里便是泰山十八盘的起点。此处山势陡峭，登山的人一个不小心很
容易便会跌堕到崖谷之中。
LONG
);
	set("exits", ([
		"northup" : __DIR__"shengxian",
		"southdown" : __DIR__"wudafu",
	]));
	set("objects", ([
		__DIR__"npc/chi" : 1,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}
