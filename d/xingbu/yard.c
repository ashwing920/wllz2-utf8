// /d/beijing2/xingbu/yard.c

inherit ROOM;

void create()
{
	set("short", "刑部庭院");
	set("long", @LONG
在这个小小的庭院里，每到开审案件的时候，总是挤满了听审的群众。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"gate",
		"east" : __DIR__"hall",
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);

}

