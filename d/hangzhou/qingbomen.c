// qingbomen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "清波门");
	set("long", @LONG
园门口有一大门楼，大匾上刻着“清波门”。门楼下站着几个嬉嬉哈
哈的少女，惹人坠步相观。在往西就进了聚景，往东便回到大路。
LONG
);
	set("exits", ([
		"east"   : __DIR__"road14",
		"west"   : __DIR__"jujingyuan",
	]));
	set("objects", ([
		"/d/center/npc/girl" : 2,
	]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
