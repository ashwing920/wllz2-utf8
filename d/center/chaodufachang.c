// chaodufachang.c - 超渡法场
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
	set("short", "超渡法场");
	set("long", @LONG
这里是桃源城里做法事，超度亡魂的超度法场。法场中设有一法坛，
一个身披大红袈裟的禅师正手持桃木剑，口中默念口诀，正在为一些亡魂
做法超度。地上撒满了纸花和纸钱，你突然间感到心情十分沉重。
LONG
);

	set("exits", ([
		"east"  : __DIR__"roadn5",
	]) );
	set("objects", ([
		__DIR__"npc/chanshi": 1,
	]) );

	setup();

	replace_program(ROOM);
}
