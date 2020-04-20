// didao4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
你一到这里，迎面就闻到一股腐烂的泥土的味道，不过从前面的亮光
中，你又看到了希望，你不禁开始加快脚步，想看看那里到底有些什么东
西。 
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"didao5",
		"up" : __DIR__"didao3",
	]));
	setup();
	replace_program(ROOM);
}

