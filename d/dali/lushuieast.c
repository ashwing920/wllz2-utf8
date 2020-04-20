//Room: /d/dali/lushuieast.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","东泸水河谷");
	set("long",@LONG
西面这一大片河谷处在碧罗雪山和高黎山之间，由东泸水冲刷而成，
地势低洼，因而气候较温暖，聚居了大量乌夷族人。乌夷先民沿河谷开发
了一些梯田。四周山高林密，男子多从事狩猎。沿着脚下的向西直抵一个
大镇子。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"westdown"   : __DIR__"badidian",
		"eastup"	 : __DIR__"biluoxueshan",
	]));
	setup();
	replace_program(ROOM);
}

