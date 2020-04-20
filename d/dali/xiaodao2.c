//Room: /d/dali/xiaodao2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","林间小道");
	set("long",@LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的树林
这里人迹罕至，惟闻足底叩击路面，微风吹拂树叶，沙沙作响。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"heilongling",
		"west"	  : __DIR__"southgate",
	]));
	setup();
	replace_program(ROOM);
}

