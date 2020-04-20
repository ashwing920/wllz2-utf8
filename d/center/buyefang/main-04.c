// main-04.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","不夜舫大堂");
        set("long",@LONG
这里是不夜舫的大堂，只见大堂之上，宾客满座，人头攒攒。南边有
一个看台，一个眉清目秀，举止端雅的女子正在台上唱歌，不时看了你一
眼。环顾四方，只见大堂上坐着的，都是一些衣冠鲜艳的达官贵人，正在
陪酒女的陪伴下，高声阔论，划拳喝酒。嬉闹声，叫嚷声，歌声，杯瓶碰
撞声掺杂在一起，十分嘈杂。南边有一条楼梯，通往不夜舫二楼。
LONG
);
        set("exits",([
                "south": __DIR__"main-03",
                "northup": __DIR__"main-2f",
        ]));
/*
        set("objects",([
                "/d/center/npc/wuming": 1,
        ]));
*/
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();

}
