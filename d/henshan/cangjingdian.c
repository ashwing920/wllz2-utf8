// Room: /d/henshan/cangjingdian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "藏经殿");
	set("long", @LONG
藏经殿深掩祥光峰下，因藏明太祖所赠大藏经故名。这里古木参天，
殿宇飘翼，奇花异草，林壑幽深，景色秀丽，藏经殿之秀是衡山大四绝之
一。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east"   : __DIR__"shanlu14",
		"south"  : __DIR__"shuzhuangtai",
	]));
	setup();
	replace_program(ROOM);
}

