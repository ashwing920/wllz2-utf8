// dadao2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "沿湖大道");
	set("long", @LONG
一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵人。
本来风景秀丽之处，却显的一片萧瑟。大道向西南和北延伸。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"dadao1",
		"southwest" : __DIR__"dalu1",
	]));
	set("outdoors", "hangzhou");
	setup();
}
