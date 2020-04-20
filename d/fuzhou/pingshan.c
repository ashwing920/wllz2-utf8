// Room: /d/fuzhou/pingshan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "福州屏山");
	set("long", @LONG
屏山古称越王山，横亘福州城北，山下华林寺，构法考究。屏山上俯
瞰榕城，历历如画。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"beidajie",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

