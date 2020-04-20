// citong_b1.c 刺桐北路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。西北方连着
一条巷子，可通往城隍庙。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n1",
		"south" : __DIR__"citong_n3",
                "northwest" : __DIR__"chxiang",
                "east" : __DIR__"guanchaidian",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 2,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
