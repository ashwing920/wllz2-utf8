// Room: /d/dali/badidian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","巴的甸");
	set("long",@LONG
这里就是大理西部要镇巴的甸，是乌夷的重要治府，多个乌夷部落分
布在附近。坐于东泸水谷地正中，巴的甸四周多农田，以此为中心，道路
四通八达连接各方的部落。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"zhenxiong",
		"south"	  : __DIR__"lushui",
		"eastup"  : __DIR__"lushuieast",
	]));

	setup();
	replace_program(ROOM);
}


