//Room: /d/dali/zonglichu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","国务总理处");
	set("long",@LONG
总理处是镇南王皇太弟总理国务之处，满桌的奏章整理得井井有条。
四周摆了很多茶花，争奇斗艳。茶花是大理国花，看来主人对它也是钟爱
有加。
LONG
);
	set("objects", ([
		__DIR__"obj/shanchahua": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"sikong",
		"south"  : __DIR__"wfdating",
		"east"   : __DIR__"sima",
		"west"   : __DIR__"situ",
	]));
	setup();
	replace_program(ROOM);
}

