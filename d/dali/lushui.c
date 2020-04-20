//Room: /d/dali/lushui.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","泸水沿岸");
	set("long",@LONG
一条土路沿着泸水纵贯谷地南北，脚下泸水滔滔流去，长年累月冲刷
着谷中大地，东面碧罗雪山、西面的高黎山皆高耸蔽日。土路北通此谷中
心大镇巴的甸，南连数个乌夷小部落。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"badidian",
		"south"	  : __DIR__"atoubu",
	]));
	setup();
	replace_program(ROOM);
}

