// nroad6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
你走在一山路上，四周有一座座小山丘。远处可以看见终年积雪的山
尖。周围的树草已经很难看得到了。
LONG
);
	set("exits",([
		"north"   : __DIR__"nroad7",
		"southup" : __DIR__"nroad5",
	]));
	set("objects",([
		__DIR__"npc/huatiegan" : 1,
	]));
	set("outdoors", "xueshan");
	setup();
	replace_program(ROOM);
}

