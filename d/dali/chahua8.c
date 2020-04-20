//Room: /d/dali/chahua8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","茶花园后门");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花园后
门口，对着满园春色，不禁大喜过望。东边就进园了，西面是一条石铺甬
道。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"east"   : __DIR__"chahua7",
		"west"   : __DIR__"yongdao2",
	]));

	setup();
	replace_program(ROOM);
}

