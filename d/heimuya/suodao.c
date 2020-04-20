// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "索道");
	set("long", @LONG
来到这条索道，两边是深不见底的崖谷，岩壁两侧设有铁索以作扶拦。
LONG
);
	set("exits", ([
		"westdown" : __DIR__"baichi",
	]));
	set("objects", ([
		__DIR__"npc/rygirl" : 1,
	]));
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
 
