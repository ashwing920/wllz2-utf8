// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "仙人指路");
	set("long", @LONG
这仙人指路其实是东面仙人洞处垂下的一道石梁，远远搭上西边的莲
花崖。
LONG
);
	set("exits", ([
		"eastup" : __DIR__"xian",
		"westup" : __DIR__"lianhua",
	]));
	set("objects", ([
		__DIR__"npc/hudie": 2,
	]) );
	set("outdoors","riyue");
	setup();
	replace_program(ROOM);
}
