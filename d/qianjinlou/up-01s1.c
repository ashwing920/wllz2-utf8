// up-01s1.c - 千金楼（走廊）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是千金楼二楼的走廊。走廊上铺设着一条红色的地毯，天花板上
，则挂着一排灯笼，把整条走廊照耀得一片通亮。走廊两边是千金楼的厢
房，大门上还挂着一块快牌子。
LONG
        );

        // set("outdoors", "qianjinlou");

        set("exits", ([
                "east"  : __DIR__"up-01s1e",
                "west"  : __DIR__"up-01s1w",
                "south" : __DIR__"up-01s2",
                "north" : __DIR__"up-01",
        ]));

        setup();

        replace_program(ROOM);
}