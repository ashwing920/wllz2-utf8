//Room: /d/dali/tingyuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","庭院");
	set("long",@LONG
这里是镇南王府的庭院，中间一个小水潭，边上种着许多不知名的花
，几只喜鹊在花丛中蹦来跳去，花丛边有片小竹林，竹影下放着石桌石凳
，经常有人在这下棋。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"shijing",
		"east"  : __DIR__"chahua1",
		"north" : __DIR__"changlang",
	]));
	setup();
	replace_program(ROOM);
}
