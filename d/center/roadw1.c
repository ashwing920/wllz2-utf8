                           // roadw1.c - 桃源西街
// Design By Robert 蝴蝶君 emial:robert_st@263.net

#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short", "桃源西街");
        set("long", @LONG
这里是桃源城的西大街。你走在一条繁忙的街道上，看着操着南腔北
调的人们行色匆匆，许多人都往东边走去，那里有一个热闹的广场。南边
是一家钱庄，可以听到叮叮当当的金银声音。北边是一间茶楼，说唱评书
的应有尽有，吸引了不少游客和武林侠士前来，是一个打听江湖消息的好
地方。
LONG
);

        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"guangchang",
                "south" : __DIR__"bank",
                "west"  : __DIR__"roadw2",
                "north" : __DIR__"yingxionglou",
        ]));
        set("objects",([
                "/d/dali/npc/jianghuyiren": 4,
        ]));
        setup();

        replace_program(ROOM);
}
