// Room: /d/gaibang/underdl.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "大和街边");
	set("long", @LONG
这是大理城中大和街边上的大树洞。里面破破烂烂的，丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
);
	set("exits", ([
		"out"	   : "/d/dali/dahejieeast",
		"northeast" : __DIR__"dlandao2",
	]));
	setup();
	replace_program(ROOM);
}

