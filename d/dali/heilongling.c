//Room: /d/dali/heilongling.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","黑龙岭");
	set("long",@LONG
黑龙岭上有红梅二株，干已剥蚀贻尽，仅存枯皮，古质斑斓，横卧于
地，离奇乔异，如骄龙，如横峰，而花朵攒躜，又如锦片，如火球，清芳
袭人，不知植自何代，相传以为唐梅，疑或然也。南面就是黑龙潭。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"xiaodao1",
		"south"	  : __DIR__"shulinwai",
		"southwest"  : __DIR__"xiaodao2",
	]));
	setup();
	replace_program(ROOM);
}

