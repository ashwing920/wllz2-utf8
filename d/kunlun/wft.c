// Room: /d/kunlun/wft.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "望峰亭");
        set("long", @LONG
长长的阶梯也终将到了尽头, 阶梯的尽头矗立著一座山门, 山门上龙
飞凤舞地写了三个字, 笔力苍劲有力显得气势非凡。山风吹来带著丝丝的
寒意, 令你有股高处不胜寒的感觉。
LONG
);
        set("objects",([
                __DIR__"npc/dizi" : 2,
        ]));
        set("outdoors","kunlun");
        set("exits", ([
                "east" : __DIR__"zhp",
                "south" : __DIR__"zwf",
                "north" : __DIR__"klpsm",
                "west" : __DIR__"ssy",
        ]));
        set("objects",([
                CLASS_D("kunlun") +"/master_kunlun": 1,
        ]));
        setup();
        replace_program(ROOM);
}
