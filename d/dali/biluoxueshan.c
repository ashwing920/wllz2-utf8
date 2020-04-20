// Room: /d/dali/biluoxueshan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","碧罗雪山");
	set("long",@LONG
你身处一片大雪山之中，此地只是半山腰，却已经积雪皑皑，寒风刺
骨了。仰头望去，银白的峰尖似在云中，天空也蓝得特别深邃。由此向上
的山颠杳无生命的踪迹，只向下百丈的山腰便是树木苍郁、飞禽走兽横行
的世界了。向东不远有一条大河流过，在崇山峻岭之间冲击出一片谷地。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"   : __DIR__"shanlu2",
		"westdown"   : __DIR__"lushuieast",
	]));
	setup();
	replace_program(ROOM);
}

