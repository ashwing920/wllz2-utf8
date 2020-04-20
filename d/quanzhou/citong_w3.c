// citong_x1.c 刺桐西路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "刺桐西路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。
LONG
);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
