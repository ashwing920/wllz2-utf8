// Room: /d/shaolin/houshan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
你站在最中间的土屋前。土屋似乎是用本地的山岭土夯筑的，结实而
且耐水。屋顶是茅草铺的，角上露出几个被风吹开的破洞。左边的屋子好
象是间猪舍，右边的土屋门边挂着几串晒干的辣椒。正中间土屋的门是开
着的。
LONG
);
	set("exits", ([
		"east" : __DIR__"xiaojing2",
		"north" : __DIR__"xiaowu",
		"northeast" : __DIR__"chufang2",
		"northwest" : __DIR__"zhushe",
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

