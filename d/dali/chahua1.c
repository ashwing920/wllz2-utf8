//Room: /d/dali/chahua1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","茶花园门");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花园口
，对着满园春色，不禁大喜过望。东边就进园了，北边是一个库房。南边
是一栋厢房。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"bingqiku",
		"south"  : __DIR__"xiuxishi",
		"east"   : __DIR__"chahua2",
		"west"   : __DIR__"tingyuan",
	]));
	setup();
	replace_program(ROOM);
}

