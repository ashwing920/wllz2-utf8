// roads4.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short","桃源南街");
        set("long", @LONG
你走在桃源南大街上，踩着坚实的青石板地面。东边是桃源城里的济
世堂，是一个救济穷人的地方。西边是一家布庄，主要是出售一些防具和
衣服，吸引了不少武林侠客前来。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"jishitang",
                "south" : __DIR__"roads5",
                "west"  : __DIR__"buzhuang",
                "north" : __DIR__"roads3",
        ]));
        set("objects",([
                "/d/city/npc/polan": 1,
        ]));
        setup();
        replace_program(ROOM);
}
