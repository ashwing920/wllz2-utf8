// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "枉死城");
	set("long", @LONG
远远看去便觉得怨气冲天，到这里的都是枉死的冤魂，他们死于历代
战争，因尸骨无人收埋，家人离散，虽死但怨气不灭，逐渐聚集在一起，
阎君因为怜其可怜，也不加刑罚，只是管束在这枉死城中，但有好心人在
人间摆开水陆道场，超度亡魂，便有部分冤魂可以安息，可惜历代战祸不
绝，枉死城中的冤魂竟然越来越多。过了枉死城，便是平安道了。
LONG
);
	set("exits", ([
		"south" : __DIR__"pingan",
	]) );
	set("objects", ([
		__DIR__"npc/ghost" : 5,
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

