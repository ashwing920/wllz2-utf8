// /d/kunming/xiaolu1

inherit ROOM;

void create()
{
	set("short","小路");
	set("long", @LONG
一条小路，颇为不平，两边耸立着一些怪石，奇形怪状，甚是有趣。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"north" : __DIR__"xiaolu", 
		"south"  :__DIR__"shilin",
	]));
	setup();
	replace_program(ROOM);
}
