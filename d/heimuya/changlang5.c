// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条长长的过道，左右两旁都是墙，每隔四五丈，墙上都点着一支明
晃晃的巨烛。
LONG
);
	set("exits", ([
		"east" : __DIR__"houdian",
		"south" : __DIR__"houhuayen",
		"north" : __DIR__"dadian",
		"west" : __DIR__"fengleitang",
	]));
	set("objects", ([
		__DIR__"npc/shizhe" : 2,
	]));
	setup();
	replace_program(ROOM);
}
