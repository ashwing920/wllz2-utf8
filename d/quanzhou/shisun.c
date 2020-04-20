// shisun.c 石笋

inherit ROOM;

void create()
{
	set("short", "石笋");
	set("long", @LONG
这是泉州西面的一处地貌奇观，经千年风蚀形成的石笋千奇百怪，似
剑、似刀、似锥，形态各异。洞壑纵横，不知所终。南面的山谷中有一所
草庵。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"luanshi",
		"south" : __DIR__"caoan1",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
