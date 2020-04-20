//d/kunlun/klsj1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
石阶上积了层厚厚的积雪，路两旁山石嶙峋，四下静悄悄的，连半个
行人也没有。只有呼啸的北风卷起漫天飞雪，向你迎面扑来。
LONG
);
        set("outdoors","kunlun");
        set("exits", ([
                "south" : __DIR__"sbxd",
                "northup" : __DIR__"klsj2",
        ]));

        setup();
}
