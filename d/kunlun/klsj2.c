//d/kunlun/klsj2.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
眼前的石阶只有薄薄的一层冰，你不禁纳闷地抬头一望，原来石阶两
旁长满了高大的松树。树冠上压了厚厚的白雪，是以石阶上没雪。北风吹
过，积雪向你迎头砸下，你不禁打了个哆嗦。
LONG
);
        set("outdoors","kunlun");
        set("exits", ([
                "southdown" : __DIR__"klsj1",
                "northeast" : __DIR__"klt",
        ]));

        setup();
}
