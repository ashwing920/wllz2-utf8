//Room: /d/dali/chahuashan3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","茶花山");
	set("long",@LONG
你走在茶花山上，这里遍地是生长茂盛的茶花。当然，大部分是凡品
，但偶尔也会有一两株佳品藏匿其中。西望不远是大理城的北门。有一些
毒蜂在飞来飞去，似乎毒蜂巢(fengchao)就在附近茶花丛里。
LONG
);
	set("objects", ([
		__DIR__"npc/bee": 3,
	]));
	set("item_desc", ([
	   "fengchao" : "这是一个野毒蜂的蜂巢。\n",
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"	 : __DIR__"chahuashan2",
	]));
	setup();
	replace_program(ROOM);
}

