// Room: /d/shaolin/xiaojing1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
这里是少室山之阳的一座山坡山坡上长满了艳红色的不知名的野花采
密的蜂蝶们簇成一团团忙碌着。不时有几只好奇的小密蜂飞近来似乎对你
这个不速之客感到极大的惊奇。
LONG
);
	set("exits", ([
		"east" : __DIR__"shijie1",
		"northup" : __DIR__"xiaojing2",
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

