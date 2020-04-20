// road.c 桃源大道
// Design By BMW add from 2000.3.26

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","桃源大道");
	set("long",@LONG
这是桃源山庄通往各位英雄隐居之地，北面是$HIY$银枫小筑$NOR$。南面隐居着
$HIR$慕容蝶衣$NOR$和$HIR$剑锺$NOR$。
LONG
);
	set("exits",([
		"east"    : __DIR__"road_6",
	]));
	setup();
	replace_program(ROOM);
}
