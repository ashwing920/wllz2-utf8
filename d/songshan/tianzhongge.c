// Room: /d/songshan/tianzhongge.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "天中阁");
	set("long", @LONG
天中阁是中岳庙的大门，原称黄中阁。庙内有古柏三百余株，金石碑
碣百余座。庙前石翁仲，雕制古朴。南面是嵩山的出口太室阙。
LONG
);
	set("outdoors","songshan");
	set("exits", ([
		"north" : __DIR__"chongsheng",
		"south" : __DIR__"taishique",
	]));
	setup();
	replace_program(ROOM);
}

