//Room: /d/dali/road1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","官道");
	set("long",@LONG
这是一条蜿蜒崎岖的山间土路，是由中原通向大理的官道。此处属川
南，向西南去的盘山路通上云贵山区，继而可达南昭大理国，此去向北不
远就是蜀中名川--峨嵋山。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"northeast"  : "/d/emei/qsjie2",
		"southwest"  : __DIR__"road2",
	]));
	setup();
	replace_program(ROOM);
}

