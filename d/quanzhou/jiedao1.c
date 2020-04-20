// jiedao1.c 街道
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是泉州南面东西向的一条干道，规模不大。南去可达海外交通使节
府，东面是一所绸缎庄。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"silkshop",
		"south" : __DIR__"jiedao2",
		"north" : __DIR__"tumen",
	]));
	set("objects", ([
		__DIR__"npc/liumangtou" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
