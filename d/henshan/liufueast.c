// liufueast.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "刘府东厢房");
	set("long", @LONG
这儿是东厢房，这儿整理得干干净净，窗外露出点绿绿的枝叶，家具
上一尘不染，地上铺着很大块的青砖，一点灰尘也不沾。
LONG
);
	set("exits", ([
		"west"   : __DIR__"liufudating",
	]));
	set("objects", ([
		__DIR__"npc/liufuren" : 1,
	]));
	setup();
	replace_program(ROOM);
}
