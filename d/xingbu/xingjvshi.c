// /d/beijing2/xingbu/hall.c

inherit ROOM;

void create()
{
	set("short", "刑部大厅");
	set("long", @LONG
刑部的刑具室，摆放着各种各样的刑具。如：皮鞭，木棍，手指套。
还有三个铡刀，分别雕成龙，虎，狗的模样。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"south": __DIR__"hall",
	]));
	setup();
	replace_program(ROOM);

}

