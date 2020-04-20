//Room: /d/dali/yanan2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","沿池小路");
	set("long",@LONG
这是一条沿着滇池南岸的小路，柳荫夹岸，清风袭人。远望滇池湖面
，碧波荡漾，飞鸟戏水，遥遥可见游船、渔船轻帆浮云。端地是人间仙境
。此路向西直上滇池西岸的群山。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"east"	: __DIR__"yanan1",
		"westup"  : __DIR__"bijishan",
	]));
	setup();
	replace_program(ROOM);
}

