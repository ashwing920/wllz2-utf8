// main-03.c 
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","沁芳亭");
        set("long", @LONG
这里是千金楼的沁芳亭。沁芳亭中装饰的十分别致，亭顶上方采用大
红琉璃瓦铺设，在阳光的照射下，显得十分鲜艳。沁芳亭西周种着一些十
分鲜艳的花朵，不时散发出阵阵幽幽的清香。
LONG
);
        set("exits", ([
                "south"  : __DIR__"main-03s1",
                "north"  : __DIR__"main-03n1",
                "west"   : __DIR__"main-02",
        ]));
        set("objects", ([
                __DIR__"npc/mingji-b": 1,
                __DIR__"npc/mingji-c": 1,
	]) );

        setup();

        replace_program(ROOM);
}