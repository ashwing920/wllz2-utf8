// Room: /d/henshan/beimen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "正北门");
	set("long", @LONG
南岳大庙正北门是大庙的后门，正在衡山山麓。回望大庙，红墙黄瓦
，金碧辉煌。北面是上山的六小路。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south"  : __DIR__"houdian",
		"northup": __DIR__"shanlu1",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

