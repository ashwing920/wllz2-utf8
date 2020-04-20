//Room: /d/dali/guibingshi2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","贵宾室");
	set("long",@LONG
这是一间贵宾室，这里窗明几亮，用具考究。单是窗边一架紫竹软榻
已是价值不菲。凭窗眺望，隐隐于淡烟之中可见苍山的玉局峰，只见山势
清秀，翠碧欲滴，令人心旷神怡。
LONG
);
	set("objects", ([
	   __DIR__"npc/shouling": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"out"	  : __DIR__"zoulang4",
	]));
	setup();
	replace_program(ROOM);
}

