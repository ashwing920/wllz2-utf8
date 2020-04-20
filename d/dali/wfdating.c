//Room: /d/dali/wfdating.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","镇南王府大厅");
	set("long",@LONG
进了大厅，放眼看那大厅，只见正中一块，横匾，写着‘邦国柱石’四个
大字，下首署着‘丁卯御笔’四个小字，楹柱中堂悬满了字画，一时也看不了
这许多。向北是镇南王总理国务见人办公之处，西边是帐房往东，是一条石径
通往内宅。
LONG
);
	set("objects",([
		__DIR__"npc/jiading": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"west"   : __DIR__"zhangfang",
		"east"   : __DIR__"shijing",
		"north"  : __DIR__"zonglichu",
		"out"	: __DIR__"wangfugate",
	]));
	setup();
	replace_program(ROOM);
}

