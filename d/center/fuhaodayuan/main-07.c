// main-07.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","小院");
	set("long", @LONG
这里是富豪院里的一所小院，通往富豪院的厨房和杂货房。小院的靠
边角落里堆放着一堆柴火，一个中年汉子正在劈柴。几个家丁正穿梭于小
院与厨房之间，显得十分忙碌。
LONG
);
        set("exits", ([
                "east":  __DIR__"main-09",
                "north": __DIR__"main-10",
                "south": __DIR__"main-06",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 1,
                __DIR__"npc/changgong": 1,
	]));

        setup();
        replace_program(ROOM);
}
