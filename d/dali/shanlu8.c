//Room: /d/dali/shanlu8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
道路在山林中蜿蜒继续，从西面的山岭通向东面的低洼地带。这里山
势较为平缓，山丛中偶有人烟，透过丛林的缝隙中向东望去，隐约可见一
汪碧水和些许人烟。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"yangzong",
		"westdown"  : __DIR__"shanlu7",
	]));
	setup();
	replace_program(ROOM);
}

