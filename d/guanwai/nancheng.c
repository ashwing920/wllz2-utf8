//guanwai/nancheng.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "南城");
	set("long", @LONG
这里是用黄土铺就的街道，街上的行人不多，看起来很冷清。偶尔有
几个身着异域服饰的行人走过，看起来是满族，鲜祖的居民。西面有一座
低埃的土房，门口挂着一个写满鲜文的幌子，还传来阵阵的肉香，看起来
象一个小饭馆。
LONG
);
	set("exits", ([
		"north" : __DIR__"jishi",
		"south" : __DIR__"muqiao",
		"west"  : __DIR__"rouguan",
	]));
	set("objects", ([
		__DIR__"npc/tengyilei" : 1,
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

