// shanlu11.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱郁的
古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭峻，山川
毓秀。往北上走是金莲阁。往南走是崎岖的山路。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"northup"   : __DIR__"jinliange",
		"southdown" : __DIR__"shanlu12",
	]));

	setup();
	replace_program(ROOM);
}
