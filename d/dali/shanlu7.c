//Room: /d/dali/shanlu7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
行进在南诏崎岖的山林中。高山耸立，雨林茂密繁盛，树木大都枝杈
横生，给行路带来额外困难。附近山民经常行走才开出这样的道路来，尽
管如此，行旅仍然需要挟带砍刀，随时准备砍除路边树木横出的障碍。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"northwest" : __DIR__"nongtian3",
		"eastup"	: __DIR__"shanlu8",
	]));
	setup();
	replace_program(ROOM);
}

