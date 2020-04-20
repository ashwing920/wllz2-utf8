// Room: /t/wanjiegu/hall.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "内堂");
	set("long", @LONG
这里放着一张大桌子，靠墙有两张凳子，白白的墙壁一尘不染，有一
个人正在屋里走来走去，显的心情焦操。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"backyard",
		"west" : __DIR__"left_room",
		"south" : __DIR__"xiaoting",
		"east" : __DIR__"right_room",
	]));
	set("objects", ([
		__DIR__"npc/zhong" : 1,
	]));
	setup();
	replace_program(ROOM);
}
