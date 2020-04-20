// /d/kunming/ndajie1

inherit ROOM;

void create()
{
	set("short",  "南大街" );
	set("long", @LONG
你走在昆明最繁华的街道上，人来人往，好不热闹，街的两旁有许多
贩卖商品的人，卖一些土特产，沿街有一些店铺，西边是一家当铺，东边
一个高高的晃字立了出来，上书"酒"。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"nandajie2", 
		"north" : __DIR__"jinrilou",
		"west"  : __DIR__"dangpu",
		"east" : __DIR__"jiulou",
	]));
	setup();
	replace_program(ROOM);
}
