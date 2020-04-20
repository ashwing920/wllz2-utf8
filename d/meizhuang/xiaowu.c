// xiaowu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
你进了这间小屋以后，发现这里竟然和你想象的差别很大，这里虽然
不能说是金碧辉煌，但到处都是玉制的物器，玉桌，玉椅，玉屏风，玉茶
壶，玉杯......数不胜数。墙上挂着一根绿玉萧和一具白玉瑶琴。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"xiaoyuan",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/huangzhong-gong" : 1,
		__DIR__"obj/wall" : 0,
	]));
	set("outdoors", "meizhuang");
	setup();
	replace_program(ROOM);
}

