// Room: /huanghe/xueguan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "学馆");
	set("long", @LONG
一间简陋的私塾，四壁皆空，屋子中摆满了学生从自己家里抬来的方
桌、长凳。一张书案放在屋子的一头，案上摆着几本翻开了的三字经、百
家姓和一把戒尺。至圣先师孔老夫子的石刻拓片侧身像贴在书案的後面。
LONG
);
	set("exits", ([
		"south"	: __DIR__"gulang",
	]));
	set("objects", ([
		__DIR__"npc/xiucai" : 1,
	]));
	setup();
	replace_program(ROOM);
}

