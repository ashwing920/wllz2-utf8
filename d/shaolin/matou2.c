// Room: /d/shaolin/matou2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "北码头");
	set("long", @LONG
这里是汉水北岸的一个码头，和『小武昌』隔河相望。虽然没有南码
头那么热闹，但也是三天一小警、五天一大集的。往北走不多远就是闻名
天下的「少林寺」。偏向东北方向则是去往京城的官道。
LONG
);

	set("exits", ([
		"west" : __DIR__"hanshui2",
	]));

	set("objects", ([
		"/d/city/npc/chuanfu2" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

