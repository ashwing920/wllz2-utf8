//Room: /d/dali/dating.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大厅");
	set("long",@LONG
这里是五华楼的前大厅，异常宽敞明亮，足有一里见方，全是云石铺
地，黑白相间，足足可以容纳二、三千人。时时可见锦衣侍者手托美食来
回行走。
LONG
);
	set("objects", ([
		__DIR__"npc/shizhe": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
		"north"   : __DIR__"louti",
		"out"	 : __DIR__"gudao",
	]));
	setup();
	replace_program(ROOM);
}

