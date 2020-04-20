// shuiguan.c 涂门水关

inherit ROOM;

void create()
{
	set("short", "涂门水关");
	set("long", @LONG
这是去往港口的主要通道，横跨小溪之上，巍然矗立，可谓巧手天成
，别具一格。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"lingmu",
		"west" : __DIR__"tumen",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
