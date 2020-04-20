// road9.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。
大道延伸向西边。断桥在大道的西南边。南边则是另一条大道。
LONG
);
	set("exits", ([
		"west"	  : __DIR__"road8",
		"south"	 : __DIR__"road10",
		"southwest" : __DIR__"duanqiao",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
