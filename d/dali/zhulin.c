//Room: /d/dali/zhulin.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","竹林小路");
	set("long",@LONG
一条小路穿竹林而过，西南方竹林深处是一大片台夷人聚居的村镇，
东北可遥遥望见喜州城的城墙。道路两边竹林茂密，时有台夷人来砍伐。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"southwest"  : __DIR__"wuding",
		"northeast"  : __DIR__"xizhou",
	]));
	setup();
	replace_program(ROOM);
}

