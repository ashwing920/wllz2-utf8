//Room: /d/dali/luyuxi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","绿玉溪沿岸");
	set("long",@LONG
一条颇宽敞的土路沿着绿玉溪南岸横贯东西，一边是涓涓溪流碧波荡
漾，另一边是青山翠柳，郁郁葱葱的林木。东面有桥渡溪通向大理城南门
，西去不远就是五华楼了。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"east"	  : __DIR__"shuangheqiao",
		"west"	  : __DIR__"gudao",
	]));
	setup();
	replace_program(ROOM);
}

