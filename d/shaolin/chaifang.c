                              // ROOM : /d/shaolin/chaifang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","柴房");
        set("long",@LONG
这里是少林寺的柴房，少林每天做饭需要大量的柴火，脚落里有一堆
还没有劈好的木头，几个僧人手拿柴刀，用力的劈着木头，一个壮年僧人
正在指挥大家干伙儿。
LONG
);
        set("exits",([
                "west" : __DIR__"chufang",
        ]));
        setup();
        replace_program(ROOM);
}
