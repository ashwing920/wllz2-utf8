// main-04.c - 千金楼（曲桥）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "曲桥");
        set("long", @LONG
一条小小的曲桥，把两边的走廊连接在一起。曲桥很窄，只能容纳两
个人并行，两边的围栏也只有膝盖高，如一不小心，则会摔到湖里去了，
一个年轻公子正和一个妓女坐在围栏边上，窃窃私语，不时发出阵阵嬉笑
声。
LONG
);

        set("outdoors", "qianjinlou");
        set("exits", ([
                "south"  : __DIR__"main-03se2",
                "north"  : __DIR__"main-03ne2",
        ]));

        set("objects", ([
                __DIR__"npc/mingji-f": 1,
                __DIR__"npc/nianqing-gongzi": 1,
	]) );

        setup();

        replace_program(ROOM);
}