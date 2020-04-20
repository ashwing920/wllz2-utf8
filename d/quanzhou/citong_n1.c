// citong_n1.c 刺桐北路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。东边是都督
巷，可通往都督府。一队队的士兵穿来插去，把守森严。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"duxiang",
		"north" : __DIR__"weiyuan",
		"south" : __DIR__"citong_n2",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
