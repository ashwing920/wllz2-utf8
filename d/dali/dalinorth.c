//Room: /d/dali/dalinorth.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大理城北");
	set("long",@LONG
这里是个岔路口。南边就是大理城的北门了，道路从这里分岔，北去
可到太和城，西北通向下关城，也通苍山，是去游苍山和崇圣寺的必经之
路。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"taihecheng",
		"south"	  : __DIR__"northgate",
		"northwest"  : __DIR__"ershuiqiao",
	]));
	setup();
	replace_program(ROOM);
}

