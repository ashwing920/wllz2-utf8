// Room: /d/hengshan/tongyuangu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "通元谷");
	set("long", @LONG
通元谷孤处见性峰下，相传为张果老成仙前修道之所，由于他道号通
元，这里也就成了通元谷。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"eastup"  : __DIR__"guolaoling",
	]));
	set("outdoors", "hengshan");

	setup();
	replace_program(ROOM);
}

