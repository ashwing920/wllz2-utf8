// Room: /d/fuzhou/fzroad9.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "闽中大道");
	set("long", @LONG
你走在闽江北岸大道上。福建境内无山不青，无水不翠，山陡林深少
行人，不禁让你惴惴。北面有股青烟冒起，似乎有家野店。
LONG
);
	set("exits", ([
		"northwest" : __DIR__"fzroad8",
		"north"	 : __DIR__"fzroad10",
		"east"	  : __DIR__"fzroad11",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/jia" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

