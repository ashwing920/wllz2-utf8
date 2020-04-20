//Room: /d/dali/yanchi1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","沿池堤岸");
	set("long",@LONG
这里沿湖堤岸遍植白色的素馨花，故又称“银棱河”；而它的一条分
支，堤岸栽种黄色的迎春花，故称“金棱河”，或金汁河。两河同为滇池
的出水口，又称海口。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	: __DIR__"dianchi",
		"west"	 : __DIR__"jinzhihe",
		"eastup"   : __DIR__"yanchi2",
	]));

	setup();
	replace_program(ROOM);
}

