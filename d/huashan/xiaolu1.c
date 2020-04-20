//Room: xiaopath1.c 小山路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","小山路");
	set("long",@LONG
这里是华山的一条小山路，地势较为平缓，不似其它地方那么险峻。
你走在这里，四周静悄悄的，你就象走进了一个世外桃源。
LONG
);
	set("outdoors", "xx");
	set("exits",([ /* sizeof() == 1 */
		"southwest"	 : __DIR__"yunu",
		"northeast"	 : __DIR__"xiaolu2",
	]));
	setup();
	replace_program(ROOM);
}
