// citong_b1.c 刺桐北路

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽阔，车水马龙，热闹非凡。南面是热闹
喧哗的中心广场，嘈杂的声音远远便能听到。东边有家鸿福楼。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n2",
		"south" : __DIR__"zhongxin",
		"east" : __DIR__"qzkedian",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
