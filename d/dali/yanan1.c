//Room: /d/dali/yanan1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","滇池沿岸");
	set("long",@LONG
滇池名曰池，实际上是个很大的湖，四面山上水源众多，也浇灌了大
片的农田。池水清澈凉爽，许多罗伽部的妇女在此洗衣挑水。摆夷并不以
渔业为主，不过岸边仍然建有小码头，时常有游船停靠，也有少量竹舟下
水打鱼。西边有条弯弯曲曲的小路沿着滇池南岸而去。
LONG
);
	set("objects", ([
		__DIR__"npc/cunfu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"luojiadian",
		"west"	  : __DIR__"yanan2",
	]));
	setup();
	replace_program(ROOM);
}

