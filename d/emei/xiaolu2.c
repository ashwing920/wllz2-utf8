//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: xiaolu2.c 小路

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是四川与湖北的交界。一条静悄悄的小土路，两旁有疏疏落落的农
舍耕田，但路上行人很少，都匆匆赶路。
LONG
);
	set("outdoors", "emei");
	set("exits", ([
		"south" : __DIR__"qsjie1",
		"east"  : __DIR__"xiaolu1",
	]));

	setup();
	replace_program(ROOM);
}
