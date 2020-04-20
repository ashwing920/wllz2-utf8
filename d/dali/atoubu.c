//Room: /d/dali/atoubu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","阿头部");
	set("long",@LONG
阿头部是乌杂蛮的部落，和附近的乌蛮一样，也属于乌夷。这里山高
林密，不熟的人轻率进山，很容易迷路丧命。深山对乌夷猎人来说却是聚
宝盆，山中野物皆是美味。
LONG
);
	set("objects", ([
		__DIR__"npc/lieren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"lushui",
		"westup"	 : __DIR__"gaolishan1",
		"southeast"  : __DIR__"yixibu",
	]));
	setup();
	replace_program(ROOM);
}

