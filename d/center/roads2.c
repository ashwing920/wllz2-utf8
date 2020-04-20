// roads2.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "桃源南街");
        set("long", @LONG
这里是桃源城的南大街，你踩着坚实的青石板地面。大街两边宽阔非
常，大街东边有一家赌场，客人络绎不绝，出入于赌场的多数是桃源城中
的一些达官贵人和一些赌鬼。大家西边有一所富豪大院，门庭宽阔非常，
显然住的是一户大户人家。
LONG
);
        set("outdoors", "center");
        set("objects",([
                 "/clone/npc/langzhong": 1,
        ]));
        set("exits", ([
                "east"  : __DIR__"duchang",
                "south" : __DIR__"roads3",
                "west"  : __DIR__"furen",
                "north" : __DIR__"roads1",
        ]));
        setup();
        replace_program(ROOM);
}
