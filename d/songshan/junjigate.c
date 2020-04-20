// Room: /d/songshan/junjigate.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "峻极禅院山门");
	set("long", @LONG
嵩山绝顶，古称峻极。这里是本是佛教大寺，但百年来却已成为嵩山
派掌门人的住所。西上可以到达封禅台。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"chanyuan",
		"westup"	: __DIR__"fengchantai",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
		__DIR__"npc/wan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

