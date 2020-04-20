// Roon: chaoyangpath1.c 朝阳峰小路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","朝阳峰小路");
	set("long",@LONG
这里是朝阳峰小路，山势陡峭，两边下临深谷，一不小心都会掉了下
去。
LONG
);
	set("outdoors", "xx");
	set("exits",([ /* sizeof() == 1 */
		"northeast": __DIR__"chaopath2",
		"southeast": __DIR__"square",
	]));
	setup();
	replace_program(ROOM);
}

