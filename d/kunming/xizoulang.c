// /d/kunming/xizoulang.c

inherit ROOM;

void create()
{
	set("short",  "西走廊" );
	set("long", @LONG
一条干净的走廊，从两面看去，可以欣赏到花园里的风景，只见各种
假山怪石，奇花异草，足见王府之气派。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"west"   :__DIR__"xizoulang1",
		"east"   :__DIR__"wangfu1"
	]));
	setup();
	replace_program(ROOM);	       
}
			