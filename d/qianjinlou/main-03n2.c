// main-03n2.c - 千金楼（花园）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "北花园");
        set("long", @LONG
这里是千金楼的北花园。刚踏进花园，一股幽香扑鼻而来。仔细一看
，园中种满了各式各样鲜艳的花朵：牡丹，药勺，杜鹃，月季等，园中东
面更种着一棵大槐树，几个身着艳丽的女子正在大树底下捉迷藏，不时间
传来阵阵悦耳而清脆的欢笑声。
LONG
);
        set("outdoors", "qianjinlou");
        set("exits", ([
                "south"  : __DIR__"main-03n1",
        ]));
        setup();

        replace_program(ROOM);
}