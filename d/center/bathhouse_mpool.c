// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;
#include <ansi.h>
#include <room.h>
#include "wash.h"

void create()
{
        set("short", "浸龙浴池");
        set("long", @LONG
一入门，热气扑面，白白的水气立刻包围了你。你依稀看到一个巨大
的檀木水池，水呈碧绿，散发着一种奇特的药香，水面上还漂着一片片红
红的花瓣儿，你真想一下子跳进去，闭上眼睛好好的放松洗(wash)一下。
LONG
);
        set("exits", ([
                "east" : __DIR__"bathhouse_m3",
        ]));
        set("objects", ([
                __DIR__"npc/nude_man": 2,
        ]));
        set("no_fight",1);
        set("no_beg",1);
        setup();
        create_door("east", "檀木门", "west", DOOR_CLOSED);

}

void init()
{
        add_action("do_wash", "wash");
}

int valid_leave(object me, string dir)
{
        if(dir == "east" && me->query_temp("wash"))
                return notify_fail("你还没泡完呢就想走？\n");
        return 1;
}
