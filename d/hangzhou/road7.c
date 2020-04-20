// road7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。
大道延伸向西边和东北边。朝北走便是上北山。南边则通往西泠桥。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"road8",
		"north"	 : __DIR__"shanlu8",
		"south"	 : __DIR__"xilingqiao",
		"west"	  : __DIR__"road6",
	]));
	set("objects", ([
		__DIR__"npc/youfang" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}

