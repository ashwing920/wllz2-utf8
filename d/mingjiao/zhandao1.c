//zhandao1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "栈道");
	set("long", @LONG
这里是通往明教的栈道，脚下茂林生云，极其艰险。
LONG
);
	set("exits", ([
		"northup"   : __DIR__"zhandao2",
		"southdown" : __DIR__"lhqhoumen",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
