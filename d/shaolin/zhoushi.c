// ROOM : /d/shaolin/aozhoushi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","粥室");
        set("long",@LONG
这里是少林寺的熬粥室，全寺弟子喝的粥都是从这里熬出来的，屋子
中央站着一个身体粗壮的僧人，他正在指挥一些和尚忙碌的工作着，几个
和尚倒吊在房梁上，手中各拿着一根大铁勺的在一口大锅里来回的搅拌。
LONG
);
        set("exits",([
                "east" : __DIR__"chufang",
        ]));
        setup();
        replace_program(ROOM);
}

