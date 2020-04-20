//Room: /d/dali/yushanfang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","御膳坊");
	set("long",@LONG
这里是大理国皇宫的御膳坊，这里的厨具都是金银做成的。皇帝不在
这里也就息火了，往东是长廊。
LONG
);
	set("objects", ([
		__DIR__"npc/taijian": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"hualang",
	]));
	setup();
	replace_program(ROOM);
}

