// /d/beijing2/xingbu/zoulang1.c

inherit ROOM;

void create()
{
	set("short", "刑部后院走廊");
	set("long", @LONG
刑部后院住着高英明和他的家眷，这条走廊上有四个房间，分别是高
英明的卧室，他女儿高小姐的闺房，工人房，和杂物房。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"ws-1",
		"north": __DIR__"zoulang3",
		"south": __DIR__"zoulang2",
		"west" : __DIR__"garden",
	]));
	setup();
	replace_program(ROOM);
}

