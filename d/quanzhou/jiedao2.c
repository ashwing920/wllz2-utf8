// jiedao1.c 街道

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是泉州的一条干道，南去可达海外交通使节府，东面是万国烟雨楼。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"wglou1",
		"south" : __DIR__"shijiefu",
		"north" : __DIR__"jiedao1",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
