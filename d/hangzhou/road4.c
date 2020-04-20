// road4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。
往南是洪春桥。大道则延伸向东北边。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"hongchunqiao",
		"northeast" : __DIR__"road5",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
