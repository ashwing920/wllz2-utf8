// faxisi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "法喜寺");
	set("long", @LONG
法喜寺是天竺三寺中最敞朗深幽的一座。进香的游客不时的进进出出
。往东可达龙井，朝北是下山的路。
LONG
);
	set("exits", ([
		"eastdown"  : __DIR__"shanlu4",
		"northdown" : __DIR__"shanlu3",
	]));
	set("objects", ([
		__DIR__"npc/guest" : 2,
		__DIR__"npc/seng" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
