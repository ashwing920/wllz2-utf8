// dongdajie2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以听到
守城官兵的吆喝声，与西边朗朗的读书声混杂在一起。北边是一家老字号
的药铺，南边是打铁铺，叮叮当当的声音老远就能听到。
LONG );
	set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"dongmen",
		"south" : __DIR__"datiepu",
		"west"  : __DIR__"dongdajie1",
		"north" : __DIR__"yaopu",
	]));
	set("objects", ([
	  	  __DIR__"npc/beggar": 1,
	]));

	setup();
	replace_program(ROOM);
}
