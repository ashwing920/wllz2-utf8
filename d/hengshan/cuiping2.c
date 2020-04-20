// Room: /d/hengshan/cuiping2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "翠屏山道");
	set("long", @LONG
你爬在翠屏山道上，树木遮天，难见天日。山林静谧，隐隐晨钟轻敲
，一切尘俗尽吭洗尽，山深有静气，恒山本色。
LONG
);
	set("exits", ([
		"eastup"   : __DIR__"xuankong1",
		"eastdown" : __DIR__"cuiping1",
	]));
	set("outdoors", "hengshan");
	setup();
	replace_program(ROOM);
}

