// /d/beijing2/xingbu/ws-3.c

inherit ROOM;

void create()
{
	set("short", "工人房");
	set("long", @LONG
这里是高尚书的仆人的卧房，陈设虽然简单，但是收拾的很整齐。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"zoulang3",
	]));
	setup();
	replace_program(ROOM);

}

