// yongning.c 永宁港


inherit ROOM;

void create()
{
	set("short", "永宁港");
	set("long", @LONG
永宁港是泉州三大港口之一。这里港阔水深，风平浪静。极目远眺，
海天一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。南边的姑嫂塔流
传着一个感人的故事。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"gushao",
		"northwest" : __DIR__"gangkou2",
	]));
	set("objects", ([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/kuli" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
}
