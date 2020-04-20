// roudian.c - 菜  场
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","集市菜场");
	set("long", @LONG
这里是桃源城的菜场，地面上显得湿漉漉的，一不小心，随时可能滑
倒在地。几个菜贩子蹲坐着，将菜筐里的菜用水打湿。
LONG
);
	set("outdoors", "center");
	set("exits", ([
		"south" : __DIR__"shambles",
	]) );                   
	set("objects", ([
		__DIR__"npc/yufan":1,
		__DIR__"npc/farmer": 2,
		__DIR__"npc/caifan": 1,
		__DIR__"npc/dog":1,
	]) );
	setup();
	replace_program(ROOM);
}
