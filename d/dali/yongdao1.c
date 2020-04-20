//Room: /d/dali/yongdao1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","甬道");
	set("long",@LONG
这是镇南王府的甬道。两边是密密的树林，风吹得树叶沙沙声响石砌
的甬道路面两侧，是如茵的绿草，点缀着一星半点的小花，周围十分安静。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"northeast" : __DIR__"yongdao2",
		"south"	 : __DIR__"tingfang",
	]));
	setup();
	replace_program(ROOM);
}

