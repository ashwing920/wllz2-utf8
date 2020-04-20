// /d/beijing2/xingbu/ws-4.c

inherit ROOM;

void create()
{
	set("short", "杂物房");
	set("long", @LONG
这是摆放杂物的房间。这里所有的东西都布满了灰尘，显示已经很久
没有人到过这里了。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang4",
	]));
	setup();
	replace_program(ROOM);

}

