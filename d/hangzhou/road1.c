// road1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大道上挤满了来灵隐寺上香和上飞来峰的游客。北边过了小溪就是灵
隐寺了。南边是上飞来峰的路。
LONG
);
	set("exits", ([
		"northwest" : "/d/quanzhou/jxnanmen",
		"northeast" : __DIR__"road2",
		"north"	 : __DIR__"lingyinsi",
		"south"	 : __DIR__"feilaifeng",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
