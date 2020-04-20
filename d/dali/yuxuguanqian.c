//Room: /d/dali/yuxuguanqian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","玉虚观前");
	set("long",@LONG
东面一座庙观，门前匾上写着“玉虚观”三个大字，西边一个碧水荡
漾的小湖，四周绿柳成荫，实乃修心养性的好地方。
LONG
);
	set("objects", ([
		__DIR__"npc/xiaodaogu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"yuxuguan",
		"south"  : __DIR__"hudiequan",
	]));
	setup();
	replace_program(ROOM);
}

