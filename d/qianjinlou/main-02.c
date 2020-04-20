// main-02.c - 千金楼

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "垂花门");
        set("long", @LONG                                                                
这里是千金楼的垂花门。只见一面粉红色的纱帘遮住了大门，纱帘上
绣满了一些做工精致的小花，煞是好看。透过纱帘，你可以看见东面有一
座凉亭，几个衣着鲜艳的女子正在凉亭中嬉闹，不时传出阵阵嘻嘻哈哈的
欢笑声。
LONG
);
        set("exits", ([
                "east"  : __DIR__"main-03",
                "west"  : __DIR__"main-01",
        ]));

        setup();

        replace_program(ROOM);
}