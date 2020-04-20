
inherit ROOM;

void create()
{
	set("short", "墨池");
	set("long", @LONG
一汪黑色的池水，还没走进就闻到一股浓浓的墨香。看来是有人常常
在此清洗笔砚，日积月累，整池的碧水就变成了一池墨水。
LONG
);
	set("outdoors","tangmen");
	set("exits", ([
		"north" : __DIR__ "danqingge",
	]));
	setup();
	replace_program(ROOM);
}

