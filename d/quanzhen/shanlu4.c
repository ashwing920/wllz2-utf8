// shanlu4.c 山路
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是山路的尽头，南面好象有一片小树林，折而向东，就是终南山
的山脚了。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([
		"northwest" : __DIR__"shanlu2",
		"eastup" : __DIR__"shanjiao",
	]));

	setup();
	replace_program(ROOM);
}
