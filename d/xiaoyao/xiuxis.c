// xiuxis.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是一间在树林中的小屋，屋子中间摆着几张大床，几张桌子，看来
是个休息的地方，室中光线柔和，使人更增睡意。
LONG
);
	set("exits", ([ 
		"east" : __DIR__"xiaodao2", 
	]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
