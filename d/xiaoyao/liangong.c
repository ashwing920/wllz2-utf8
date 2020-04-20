// liangong.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","石屋");
	set("long", @LONG
这是树林中的一间石屋，屋内显得什么清净和简朴，房间中并没有什
么特别的摆设在这里，不会受到任何东西的骚扰，是个修炼内功的好地方。
LONG
);
	set("exits",([
		"south" : __DIR__"xiaodao4",
	]));
	set("sleep_room",1);
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
