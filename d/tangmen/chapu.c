#include <room.h>

inherit ROOM;

void create()
{
        set("short", "茶铺");
        set("long", @LONG
这是路旁一个简陋的茶铺，周围满是竹林环绕，环境倒是清幽，简单
的几张竹桌。竹椅，时不时有人坐着歇歇脚，喝两口茉莉花茶。茶铺的主
人是个十五、六岁的小姑娘，可爱伶俐，来这儿就算是不喝茶，看看她也
是很开心的事儿。南边有一道竹门虚掩着。
LONG
);
        set("exits", ([ 
                "south" : __DIR__"zhulin",
                "west"  : "/d/dali/chahuashan1",
        ]));
        create_door("south", "竹门", "north", DOOR_CLOSED);
        set("objects", ([
                __DIR__"npc/tangtian" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
