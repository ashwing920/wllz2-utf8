// Room: /d/hengshan/jinlongxia.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "金龙峡");
	set("long", @LONG
金龙峡又称唐峪，是进入恒山的入口。恒山一名太恒山，或称玄岳，
是五岳中的北岳，道教以之为第五小洞天。它横亘三百余里，如一队行进
中的队列，昔人以为恒山如行来相对泰山如坐，华山如立，嵩山如卧和衡
山如飞。
LONG
);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
		"northeast"  : "/d/city2/road6",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
	]));
	set("outdoors", "hengshan");
	setup();
	replace_program(ROOM);
}

