//ROOM: /d/huashan/changlang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long",@LONG
你走在长廊上只见红栏碧瓦，雕梁画栋，廊外风吹翠竹，细吟阵阵，
看来华山剑派气派果然不凡。西面是岳夫人的居室。
LONG );
	set("exits", ([
		"west"  : __DIR__"jushi",
		"north" : __DIR__"songlin/exit",
		"south" : __DIR__"garden",
	]));
	setup();
	replace_program(ROOM);
}
