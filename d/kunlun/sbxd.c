// Room: /d/kunlun/sbxd.c 
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山边小店");
        set("long", @LONG
这里是昆仑山山脚的一间小店，由于方圆数十里就此一间小店，加上
昆仑山终年积雪，天气寒冷，而这里又有御寒衣物售卖，因此生意还算兴
隆。
LONG
);
        set("exits", ([ 
                "north" : __DIR__"klsj1",
                "northwest" : "/d/mingjiao/shanjiao",
        ]));
        set("objects", ([ 
                "/d/city/npc/xiaoer" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
