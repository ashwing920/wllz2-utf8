//Room: /d/dali/shanlu4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山路");
	set("long",@LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两旁间
或可见一些夷族的村镇。山路向南蜿蜒着。
LONG
);
	set("objects", ([
		__DIR__"npc/shennongdizi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"shanlu2",
		"southwest"  : __DIR__"shanlu5",
	]));
	setup();
	replace_program(ROOM);
}

