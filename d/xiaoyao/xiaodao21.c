// xiaodao21.c 林间小道
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条长长的林间小道，从东边一直通到西边，一眼望去，看不到
路的尽头。两旁百花争艳。令人留连忘返。南边好象有香味散发出来，西
北边是终年结冰的寒冰池。
LONG
);
	set("exits", ([ 
		"northwest" : __DIR__"xiaodao22",
		"southeast" : __DIR__"xiaodao2",
	]));

	set("outdoors", "xiaoyao");
	setup();
	replace_program(ROOM);
}
