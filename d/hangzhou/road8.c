// road8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。
大道延伸向东边和西南边。朝北走便是上宝石山。
LONG
);
	set("exits", ([
		"east"	  : __DIR__"road9",
		"northup"   : __DIR__"baoshishan",
		"southwest" : __DIR__"road7",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
