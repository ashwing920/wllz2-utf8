// caoping.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","草坪");
	set("long",@LONG
这里是一块芳草坪，绿草茵茵，蝴蝶漫舞，让人感到惬意。不过偶尔
也会碰到菜花蛇。
LONG
);
	set("exits", ([
		"west" : __DIR__"shijie",
	]));
	set("objects" , ([
		 __DIR__"npc/caihuashe" : random(2),
	]));
	set("outdoors", "baituo");
	setup();
	replace_program(ROOM);
}
