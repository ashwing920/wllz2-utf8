//Room: /d/dali/nongtian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","农田");
	set("long",@LONG
一小片在山坡下的竹林里开垦出来的农田，临有溪流，种植着水稻。
台夷生活很大程度上依靠农业，从事农业的却基本上是妇女。男子大都专
司狩猎和捕鱼。
LONG
);
	set("objects", ([
		__DIR__"npc/nongfu1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"wuding",
	]));
	setup();
	replace_program(ROOM);
}

