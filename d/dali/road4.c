//Room: /d/dali/road4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大路");
	set("long",@LONG
一条贯通南北的大路，是由大理城往南边疆土的官道。沿路向南丛林
愈发茂密，大片雨林覆盖山岭，此间地势较平坦，大路笔直地连接着北边
的大理城和南边的喜州等城镇。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"shuangheqiao",
		"south"	  : __DIR__"tianweijing",
	]));
	setup();
	replace_program(ROOM);
}

