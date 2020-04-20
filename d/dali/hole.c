//Room: /d/dali/hole.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大，小芝云洞");
	set("long",@LONG
带着火折进入洞内，迂回蛇行，不久，即见一厅豁然开朗，石钟乳，
石笋，石柱，玲珑剔透，斗奇争胜。光照壁影，如月穿晓岩，溪云接水，
壁气侵寒，石光滴翠，清幽可爱。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"out"	  : __DIR__"changhu",
	]));
	setup();
	replace_program(ROOM);
}

