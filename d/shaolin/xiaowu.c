// Room: /d/shaolin/xiaowu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小土屋");
	set("long", @LONG
土屋中间挂着一张大竹席，将后边的那半间隔作了卧房。地上放了架
木制的纺车，上面已经积满了灰尘，看来是好久没人用了。地面上的尘土
上留有几行散乱的足迹，通向席后的卧房。
LONG
);
	set("exits", ([
		"south" : __DIR__"houshan",
		"north" : __DIR__"woshi",
	]));
	setup();
	replace_program(ROOM);
}

