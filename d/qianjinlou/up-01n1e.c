// up-01n1e.c - 千金楼（厢房）

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
这里是千金楼二楼一间普通的厢房。厢房里收拾得十分干净，一张大
床陈列在厢房的右侧，床上挂着一廉粉红色的床帘，十分好看。厢房中央
有一张八仙桌，一个青年公子正和一个青楼女子在喝酒呢。
LONG
);
        set("exits", ([
                "west" :  __DIR__"up-01n1",
        ]));
        set("objects",([
        	__DIR__"npc/jinu": 1,
        	__DIR__"npc/nianqing-gongzi": 1,
        ]));
        setup();
        create_door("west","红木门","east",DOOR_CLOSED);
}