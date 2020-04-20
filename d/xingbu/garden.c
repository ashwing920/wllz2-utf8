// /d/beijing2/xingbu/hall.c

inherit ROOM;

void create()
{
	set("short", "刑部后花园");
	set("long", @LONG
只见这里鸟语花香，蝴蝶在花丛中飞舞，使你觉得自己仿佛到了仙境
似的。
LONG
);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hall",
		"east" : __DIR__"zoulang1",
	]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);

}

