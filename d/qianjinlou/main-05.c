// main-05.c - 千金楼（藕香榭）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "藕香榭");
        set("long", @LONG
这里是千金楼的藕香榭。这里环境幽雅，空气清新，四周更种满了许
多名贵的花草，花儿争鲜斗艳，引来了许多蝴蝶蜜蜂飞舞，十分好看，边
上有一张红木桌，一个打扮显贵的男子正和千金楼的几个陪酒女郎在喝酒
划拳，不时传出阵阵淫荡的欢笑声。
LONG
);

        set("exits", ([
                "east"   : __DIR__"main-06",
                "north"  : __DIR__"main-03ne4",
                "south"  : __DIR__"main-03se4",
        ]));
        set("objects", ([
                __DIR__"npc/peijiu-nu": 2,
                __DIR__"npc/jianshang": 1,
	]));
        setup();

        replace_program(ROOM);
}