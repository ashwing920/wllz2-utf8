// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一路走过，只见走廊上数百武士排列两旁，手中各挺一把明晃晃的长
刀，交叉平举，往来之人都要弓腰低头而过，数百柄长刀中只要有一柄突
然砍落，便不免身首异处。
LONG
);
	set("exits",([ /* sizeof() == 4 */
		"east" : __DIR__"yiting",
		"west" : __DIR__"dadian",
		"south" : __DIR__"houdian",
		"north" : __DIR__"changlang4",
	]));
	setup();
	replace_program(ROOM);
}
