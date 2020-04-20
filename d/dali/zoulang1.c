//Room: /d/dali/zoulang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是一条长长的走廊，通向各个客人的寝室。到了二楼，毛毡已经换
成纯白，两侧木壁上或刻有花鸟鱼虫，或挂了些许时人的字画，每隔七八
步，就有一处香台，缕缕青烟从铜鹤嘴里游出，闻之精神一振。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"down"	  : __DIR__"louti",
		"west"	  : __DIR__"zoulang2",
		"east"	  : __DIR__"zoulang3",
	]));
	setup();
	replace_program(ROOM);
}

