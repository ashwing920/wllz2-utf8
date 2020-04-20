// roadn2.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","桃源北街");
        set("long", @LONG
你走在北大街上，踩着坚实的青石板地面。西边是一些商人和趟子手
们经常出入的“龙门镖局”。这所镖局在江湖上坡有名气，据说开办至尽
数十载，还没有失手过。东边是经常顾客盈门的妓院--千金楼。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"jiyuan",
                "south" : __DIR__"roadn1",
                "west"  : __DIR__"biaoju",
                "north" : __DIR__"roadn3",
        ]));
        set("objects",([
                __DIR__"npc/nuselang": 1,
                __DIR__"npc/xiaotou":1,
        ]));
        setup();
        replace_program(ROOM);
}
