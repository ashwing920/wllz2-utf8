// caifang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","柴房");
	set("long",@LONG
这是间不宽的柴房，木柴已经快烧光了，墙角放着几把柴刀。
LONG
);
	set("exits",([
		"west" : __DIR__"chufang",
	]));
	set("objects",([
		__DIR__"npc/laocai" : 1,
	]));
	setup();
	replace_program(ROOM);
}

