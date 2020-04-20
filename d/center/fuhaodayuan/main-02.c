// main-01.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "富豪大院");
	set("long", @LONG
你来到了一个宽敞的大院当中。大院两边种满了各式各样的鲜花和青
草，芬芳非常，十分好看。大院两边各种有一棵大松树，枝叶茂盛，十分
粗壮，犹如一把大伞向四周散开，给大院里留下了一片绿荫。大院中间有
一条小石路，一直往西面的大厅延伸。
LONG
);
	set("exits", ([
		"west" : __DIR__"main-03",
		"east" : __DIR__"main-01",
	]));
	set("objects", ([
		__DIR__"npc/changgong" : 2,
	]));

	setup();
	replace_program(ROOM);
}
