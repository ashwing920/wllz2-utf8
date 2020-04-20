// guangchang.c 广场
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","广场");
	set("long",@LONG
这里是雪山寺内的广场。广场石埕铺就, 黄土垫砌, 平整而坚实。
LONG
);
	set("outdoors","xueshan");
	set("exits",([
		"east" : __DIR__"xiaoyuan",
		"west" : __DIR__"chang",
		"north" : __DIR__"dadian",
		"south" : __DIR__"shanmen",
	]));
	setup();
	replace_program(ROOM);
}


