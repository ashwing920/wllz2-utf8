// up-01.c - 千金楼（小厅）

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "二楼小厅");
        set("long", @LONG
这里是千金楼二楼的小厅。小厅之中铺设着一张红色的大地毯，中间
放着一张八仙桌，几个风尘女子正陪着一个富贵人家打扮的老爷儿一起喝
酒，不时发出阵阵淫荡的欢笑声。南北两面各有一条走廊，通往千金楼的
厢房和包厢。
LONG
);

        set("exits", ([
                "east"    : __DIR__"up-01e",
                "south"   : __DIR__"up-01s1",
                "north"   : __DIR__"up-01n1",
                "down"    : __DIR__"main-01",
        ]));
        set("objects",([
        	__DIR__"npc/jinu": 4,
        	__DIR__"npc/piaoke": 1,
        ]));
        	
        setup();
        create_door("east","小木门","west",DOOR_CLOSED);
}