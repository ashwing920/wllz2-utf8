//Room: /d/dali/jingzhuang3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","第三层");
	set("long",@LONG
雕绕绫坐像四座，坐像间之四面各雕佛及菩萨一组。识者谓北面多臂
观音，南面为地藏菩萨。合神佛面目和蔼，雕刻精细，造形优美。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"up"	: __DIR__"jingzhuang4",
		"down"  : __DIR__"jingzhuang2",
	]));
	setup();
	replace_program(ROOM);
}

