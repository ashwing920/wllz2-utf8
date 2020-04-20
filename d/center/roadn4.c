// roadn4.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "桃源北街");
        set("long", @LONG
这里是桃源城的北大街上，踩着坚实的青石板地面。东边是桃源城里
的一间车马店，专门出售一些良种的马匹。西边是桃源城环境最美最宁静
的大槐树园。站在这里，可以看见北面的一座庙宇，庙宇上方挂着一块牌
子，上面写着「关帝庙」三个大字。
LONG
);

        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"chemadian",
                "south" : __DIR__"roadn3",
                "west"  : __DIR__"dahuaishu",
                "north" : __DIR__"roadn5",
        ]));

        setup();

        replace_program(ROOM);
}
