// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "竹篓");
	set("long", @LONG
坐在竹篓当中，眼见轻烟薄雾从身旁飘过，仰头向黑木崖上望去，但
见那座汉玉牌楼发出耀眼的光芒。
LONG
);
	set("exits", ([ ]));
	setup();
	replace_program(ROOM);
}
