//d/kunlun/bwc.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
你正站在一间宽阔的大房间里, 这里是昆仑派弟子打坐练功的地方, 
空气中弥漫著一股股汗臭味。四周的墙壁上画著一幅幅经脉穴道图。靠近
墙壁的地上则摆著一个个练功用的木人。西边有一扇门(door)，好象是虚
掩着。
LONG
);
        set("objects", ([ 
                CLASS_D("kunlun")+"/xihuazi"  : 1,
                CLASS_D("kunlun")+"/weisiniang"  : 1,
        ]));
        set("exits", ([ 
                "north" : __DIR__"dt",
                "south" : __DIR__"klpsm",
                "east" : __DIR__"pqf",
                "southwest" : __DIR__"wgws",
                "west":  __DIR__"xis",
        ]));
        setup();
}
