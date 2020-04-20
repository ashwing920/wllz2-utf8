// main-06.c - 千金楼（歌舞厅）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "歌舞厅");
        set("long", @LONG
这里是千金楼的歌舞厅。四壁上挂满了钟鼓，几个女子正随着乐声翩
翩起舞，十分好看。几个男子正一边欣赏，一边喝酒，看起来十分陶醉的
样子。
LONG
);
        set("exits", ([
                "west"   : __DIR__"main-05",
        ]));

        set("objects", ([
                __DIR__"npc/wunu": 2+random(2),
                __DIR__"npc/nianqing-gongzi": 1,
                __DIR__"npc/jianshang":2,
                __DIR__"npc/piaoke":1,
	]) );

        setup();

        replace_program(ROOM);
}