//Room: /d/dali/zhengdian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","正殿");
	set("long",@LONG
这里是大理国皇宫的正殿，大理皇帝通常都在这里处理国事，但现在
皇帝不在，所以显得不那么拘谨，往南是长廊。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"hualang",
	]));
	setup();
	replace_program(ROOM);
}

