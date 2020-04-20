// Room: /d/songshan/tieliang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "铁梁峡");
	set("long", @LONG
由此上山，山路越发险竣。铁梁峡右侧尽是怪石，而左边则为万仞深
谷，渺不见底。隔着峡谷，青冈峰环抱青冈坪，向上是主峰的山路。
LONG
);
	set("exits", ([
		"down"	: __DIR__"luyanpubu",
		"northup" : __DIR__"shandao5",
	]));
	set("objects", ([
		__DIR__"npc/lu" : 1,
	]));
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

