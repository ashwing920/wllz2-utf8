// up-01n1.c - 千金楼

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short","走廊");
        set("long", @LONG
这里是千金楼二楼的走廊。走廊上铺设着一条红色的地毯，天花板上
，则挂着一排灯笼，把整条走廊照耀得一片通亮。走廊两边是千金楼的厢
房，大门上还挂着一块快牌子。
LONG
);

        set("exits", ([
                "east"  : __DIR__"up-01n1e",
                "west" :  __DIR__"up-01n1w",
                "north" : __DIR__"up-01n2",
                "south" : __DIR__"up-01",
        ]));

        setup();
		create_door("east","红木门","west",DOOR_CLOSED);
        replace_program(ROOM);	
        
}