// roads1.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short","桃源南街");
        set("long", @LONG
这里是桃源城的南大街。你走在一条繁忙的街道上，看着操着南腔北
调的人们行色匆匆，许多人都往北边走去，那里有一个热闹的广场。东边
是一家店铺，墙上写着一个大大的“$WHT$当$NOR$”字，仔细倾听，可以听到压低的
讨价还价的声音。西边是一家钱庄，可以听到叮叮当当的金银声音。
LONG
);

        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"hockshop",
                "south" : __DIR__"roads2",
                "west"  : __DIR__"bank",
                "north" : __DIR__"guangchang",
        ]));
        setup();
	replace_program(ROOM);
}
