// main-03.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这里是主人一家用膳的地方--饭厅。饭厅之中有一张大红木桌子，桌
子边上放着几张圆凳。饭厅里收拾整齐，让人看了十分舒服。
LONG
);
	set("exits", ([
		"east" : __DIR__"main-03",
	]));
	set("objects", ([
		__DIR__"npc/jiading":2,
	]));
	setup();
	replace_program(ROOM);
}

