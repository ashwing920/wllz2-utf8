// Room: /d/henshan/tianzhu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "天柱峰");
	set("long", @LONG
你爬上衡山五峰之一的天柱峰，四望群山缥缈云雾中，每每天阴地湿
时候，这里就是天柱云气的所在了。 
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"westdown"   : __DIR__"shanlu10",
		"eastdown"   : __DIR__"shanlu7",
	]));
	setup();
	replace_program(ROOM);
}

