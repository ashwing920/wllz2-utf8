// xinmen.c 新门集

inherit ROOM;

void create()
{
	set("short", "新门集");
	set("long", @LONG
这是泉州南面东西向的一条干道，规模不大。南边有家茶居，西边是
新门吊桥，东边则是市集。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"xmqiao",
		"east" : __DIR__"jishi",
		"south" : __DIR__"taoran",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
