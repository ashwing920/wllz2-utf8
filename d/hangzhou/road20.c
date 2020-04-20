// road20.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。
大道伸向东西两边，往北是苏堤。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"suti7",
		"west"	  : __DIR__"road19",
		"east"	  : __DIR__"road16",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
