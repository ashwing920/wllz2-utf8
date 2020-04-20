// road5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。
往西是去玉泉寺的路。大道则延伸向东边和西南边。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"road4",
		"westup"	: __DIR__"yuquan",
		"south"	 : __DIR__"dadao1",
		"east"	  : __DIR__"road6",
	]));
	set("objects" , ([
		__DIR__"npc/honghua1" :1,
		__DIR__"npc/tiao-fu" :1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
