// dadao3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "沿湖大道");
	set("long", @LONG
一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵人。
本来风景秀丽之处，却显的一片萧瑟。路的西边是一座庄园，大道向南北
延伸。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"road19",
		"north"	 : __DIR__"dalu1",
		"west"	  : __DIR__"liuzhuang",
	]));
	set("outdoors", "hangzhou");
	setup();
}
