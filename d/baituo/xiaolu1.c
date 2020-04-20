//xiaolu1
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",@LONG
这里是一条上山的小路。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"northup" : __DIR__"xiaolu2",
		"southwest" : __DIR__"dongjie",
		"northeast" : __DIR__"fende",
	]));
	setup();
	replace_program(ROOM);
}
