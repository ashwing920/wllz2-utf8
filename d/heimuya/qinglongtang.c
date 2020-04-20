// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "青龙堂");
	set("long", @LONG
大堂设许多各式的刑具，在微弱的烛光之下，散发着冰冷的寒光，令
人越看越是心中发毛，想像受刑之人那种惨状及那凄惨的叫声，心中更感
到一阵惊怖。
LONG
);
	set("objects",([
		__DIR__"npc/shizhe": 2,
	]));
	set("exits",([
		"east" : __DIR__"changlang2",
	]));
	setup();
	replace_program(ROOM);
}
