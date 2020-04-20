// main-02.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","不夜舫大堂");
        set("long",@LONG
你拨开纱帐，来到了不夜舫的大堂，只见大堂之上，宾客满座，人头
攒攒。大堂足有四丈多宽，两边整齐的摆着一排红木制成的大圆桌子。大
堂中间有一个看台，一个眉清目秀，举止端雅的女子正站在台上唱歌。环
顾四方，只见大堂上坐着的，都是一些衣冠鲜艳的达官贵人，正在陪酒女
的陪伴下，高声阔论，划拳喝酒。嬉闹声，叫嚷声，歌声，杯瓶碰撞声掺
杂在一起，十分嘈杂。
LONG
);
        set("exits",([
                "north": __DIR__"main-03",
                "out": __DIR__"main-01",
        ]));
        set("objects",([
                __DIR__"npc/chuanke": 3,
        ]));
        setup();
}
