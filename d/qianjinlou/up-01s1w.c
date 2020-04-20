// up-01s1w.c - 千金楼（厢房）
// 编程：中山大学  孔雀（Key）----ln96wgx@nct.zsu.edu.cn         1997.9

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "厢  房");
        set("long", @LONG
这里是千金楼二楼一间普通的厢房。厢房里收拾得十分干净，一张大
床陈列在厢房的右侧，床上挂着一廉粉红色的床帘，十分好看。厢房中央
有一张八仙桌，一个青楼女子正在低头看书。
LONG
);

        set("exits", ([
                "east"  : __DIR__"up-01s1",
        ]));

        set("objects", ([
                __DIR__"npc/mingji-k": 1,
                __DIR__"npc/yahuan": 1,
	]) );

        setup();

        replace_program(ROOM);
}