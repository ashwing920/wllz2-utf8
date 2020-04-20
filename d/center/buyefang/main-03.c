// main-03.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","不夜舫大堂");
        set("long",@LONG
这里是不夜舫的大堂，只见大堂之上，宾客满座，人头攒攒。大堂足
有四丈多宽，两边整齐的摆着一排红木制成的大圆桌子。大堂中间有一个
看台，一个眉清目秀，举止端雅的女子正站在台上唱歌。环顾四方，只见
大堂上坐着的，都是一些衣冠鲜艳的达官贵人，正在陪酒女的陪伴下，高
声阔论，划拳喝酒。嬉闹声，叫嚷声，歌声，杯瓶碰撞声掺杂在一起，十
分嘈杂。
LONG
);
        set("exits",([
                "north": __DIR__"main-04",
                "south": __DIR__"main-02",
        ]));
        set("objects",([
                "/clone/npc/shenshu": 1,
        ]));

        setup();
        replace_program(ROOM);
}
