// Room: /d/henshan/fangguangsi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "方广寺");
	set("long", @LONG
方广寺在莲花峰下。莲花峰有八个山头，犹如金莲瓣瓣，方广寺就建
在这莲花中心的一片平地上。深邃幽雅，有不游方广寺，不知南岳之深之
说，故方广寺之深为衡山大四绝之一。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"southdown"  : __DIR__"shanjian",
		"eastup"	 : __DIR__"shanlu10",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

