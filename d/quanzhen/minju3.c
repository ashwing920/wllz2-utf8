// minju3.c 民居
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一所乡间民居，桌椅都很旧了，而且看得出来是自己敲敲打打给
拼补下来的，不过擦拭得很干净。墙壁上斜倚着一支猎叉，也许这家的主
人还是个捕猎高手。
LONG
	);
	set("exits", ([
		"southeast" : __DIR__"guchang",
	]));
	setup();
	replace_program(ROOM);
}
