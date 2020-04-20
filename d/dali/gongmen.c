//Room: /d/dali/road1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","");
	set("short", "宫门");
	set("long",@LONG
这里是大理皇宫的宫门，门口放着两个高大石狮，大理皇帝没有一点
架子，从来不禁止人们进入皇宫，往南是御街，往北就进入皇宫了。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"qiandian",
		"south"  : __DIR__"yujie",
	]));
	setup();
	replace_program(ROOM);
}

