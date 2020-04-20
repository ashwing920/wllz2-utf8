//Room: /d/dali/jingzhuang7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","第七层");
	set("long",@LONG
这里是经幢的顶部，圆弧形顶篷，向徵天穹。上面刻有诸天神佛，飞
天力士等。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"down"  : __DIR__"jingzhuang6",
	]));
	setup();
	replace_program(ROOM);
}

