//Room: /d/dali/hongsheng4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","宏圣寺塔");
	set("long",@LONG
这里是宏圣寺塔内部，四面墙壁上都辟有佛龛，龛内置佛像。西面塔
壁由模印砖所砌，上面用梵，汉文刻了阴形文的“阿众佛灭正保咒”。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"down"	 : __DIR__"hongsheng3",
	]));
	setup();
	replace_program(ROOM);
}

