// chashi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "茶室");
	set("long", @LONG
这里是龙井茶茶室。在这里可以品到最新鲜的龙井。
LONG
);
	set("exits", ([
		"west"	 : __DIR__"longjing",
	]));
	setup();
	replace_program(ROOM);
}
