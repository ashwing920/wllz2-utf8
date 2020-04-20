// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "药房");
	set("long", @LONG
这是一间供日月教徒疗伤的药房。
LONG
);
	set("exits", ([ 
		"west" : __DIR__"chengdedian",
	]));
	set("objects",([
		__DIR__"npc/yao" : 1,
	]));
	setup();
	replace_program(ROOM);
}
