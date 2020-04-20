// Room: /d/xingxiu/xxroad6.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山间平地");
	set("long", @LONG
山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一眼清泉
。草地上树着几个毒僵尸，显是星宿弟子练功所用。
LONG
);

	set("resource/water", 1);
	set("objects", ([
		"/d/xingxiu/obj/yangrou" : 3,
		"/d/xingxiu/npc/dujiangshi" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"xxroad5",
	]));
	set("outdoors", "xingxiuhai");
	setup();
	replace_program(ROOM);
}

