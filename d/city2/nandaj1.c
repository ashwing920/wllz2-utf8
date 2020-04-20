//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这里是南大街。北边是天安门广场，南边是南大街广场。西边是一家
店铺，墙上写着一个大大的“当”字，仔细倾听，可以听到压低的讨价还
价的声音。东边是一家小客店。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"west" : __DIR__"dangpu",
		"south" : __DIR__"nandaj2",
		"east" : __DIR__"kedian",
		"north" : __DIR__"tian_anm",
	]));
	set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
		"/d/city2/npc/xiaofan" : 1,
	]));

	setup();
	replace_program(ROOM);
}

