//Room: taiziyan.c 太子岩
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","太子岩");
	set("long",@LONG
这里是群山环抱中的太子岩，岩上有一块三清石和一座太子亭。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown":__DIR__"shanlu4",
		"southdown": __DIR__"langmeiyuan",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
