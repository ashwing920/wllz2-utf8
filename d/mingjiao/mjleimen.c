// Room: /d/mingjiao/mjleimen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "青石地");
	set("long", @LONG
这是一片青石地，静穆无尘。斜晖淡扫，石栏映日，辉影雪山。三三
两两高鼻深目，雪肤金发男女教众急步匆匆来去，所配兵器也非中土能见。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"mjleimen1",
		"northeast" : __DIR__"mjsimen1",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
