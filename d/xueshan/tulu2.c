// tulu2.c 土路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com


inherit ROOM;

void create()
{
	set("short","土路");
	set("long",@LONG
这是一条不起眼的土路，却是连接雪山寺与中原的必经之路。西边点
点的炊烟依稀可见。往北可以通往声震西域的雪山寺。
LONG
);
	set("outdoors","xueshan");
	set("exits",([
		"east" : __DIR__"tulu1",
		"north" : __DIR__"tulu3",
		"west" : __DIR__"kedian",
	]));
	setup();
	replace_program(ROOM);
}

