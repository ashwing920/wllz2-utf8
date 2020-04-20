// Room: /d/henshan/nantaisi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com
		
inherit ROOM;

void create()
{
	set("short", "南台寺");
	set("long", @LONG
南台寺为禅宗七祖怀让的弟子石头希迁的道场，寺下紫云峰上是石头
和尚墓。寺周林荫夹道，曲径通幽，泉流叮咚，蜂蝶纷飞，山风吹过时万
叶悉索，真好去处。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"northdown"  : __DIR__"shanlu9",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

