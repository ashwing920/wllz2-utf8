// tulu1.c 土路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","土路");
	set("long",@LONG
这是一条不起眼的土路，不宽却也不窄，松散的浮尘显露出来往行商
的频繁。它是连接雪山寺与中原的必经之路。
LONG
);
	set("outdoors","xueshan");
	set("exits",([
		"east" : __DIR__"caoyuan",
		"west" : __DIR__"tulu2",
	]));
	setup();
	replace_program(ROOM);
}
