//Room: yunupath1.c 玉女峰山路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","玉女峰山路");
	set("long",@LONG
这里是玉女峰后山的一条山路。路边长满了翠竹，每当微风拂过，竹
叶便沙沙作响，显得分外的幽静。
LONG
);
	set("outdoors", "xx");
	set("exits",([ /* sizeof() == 1 */
		"southup"  : __DIR__"yunupath2",
		"northup"  : __DIR__"yunu",
	]));
	setup();
	replace_program(ROOM);
}

