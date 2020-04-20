//Room: /d/dali/shuitian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","水田");
	set("long",@LONG
这是一片低洼平地的农田，除了田埂，全部都被水淹没着，一些普麽
部的妇女赤着脚在田里插秧。这个地区雨水充足，虽然没有江河流过，无
需特别的灌溉，每至春夏田里自然雨水溢满。
LONG
);
	set("objects", ([
		__DIR__"npc/cow": 1,
		__DIR__"npc/nongfu1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"luwang",
	]));
	setup();
	replace_program(ROOM);
}

