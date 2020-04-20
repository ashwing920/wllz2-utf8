// tianwang.c 天王殿

inherit ROOM;

void create()
{
	set("short", "天王殿");
	set("long", @LONG
走入山门即是天王殿。左右塑天王坐像各一尊，怒目挺腰，状极威猛
。殿后则是一片宽敞的大石庭，通往后面的大雄宝殿。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dxbaodian",
		"south" : __DIR__"kaiyuan",
	]));
	set("objects", ([
		__DIR__"npc/monk" : 1,
	]));
	setup();
	replace_program(ROOM);
}
