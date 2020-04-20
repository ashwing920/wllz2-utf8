// hjting.c 花桥亭
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "花桥亭");
	set("long", @LONG
这是一个建在大路中央的小亭子，三三两两的行人在此休息。南去便
是顺济桥，可通往港口。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"jishi",
		"south" : __DIR__"sjqiao",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
