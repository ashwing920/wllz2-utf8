// main-03se3.c - 千金楼（游廊）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "游廊");
        set("long", @LONG
这是通往藕香榭的游廊，游廊采用大理石铺设，显得十分尊贵，游廊
两旁种着许多鲜艳的花草，引来一群蝴蝶飞舞着，把这里衬托得十分好看
。再往东走就是千金楼的藕香榭了。
LONG
);

        set("outdoors", "qianjinlou");

        set("exits", ([
                "west"   : __DIR__"main-03se2",
                "east"   : __DIR__"main-03se4",
        ]));

        setup();

        replace_program(ROOM);
}