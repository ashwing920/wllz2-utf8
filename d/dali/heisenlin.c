//Room: /d/dali/heisenlin.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","黑森林");
	set("long",@LONG
迎面一大片黑压压的森林，高大的古松参天而立。左首一排九株大松
树，看起来有些特别。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"	  : __DIR__"dasenlin",
	]));
	setup();
	replace_program(ROOM);
}

