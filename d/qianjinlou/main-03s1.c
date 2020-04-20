// main-03s1.c - 千金楼（白石路）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "白石路");
        set("long", @LONG
这里是通往花园的白石路。白石路上铺满细碎的沙石，却填补得十分
平整，倒也别出心裁。几个丫环打扮的女子正走来走去，十分忙碌。往北
走是千金楼的北花园，东面有一条游廊，通往千金楼的藕香榭。
LONG
        );

        set("outdoors", "qianjinlou");
        set("exits", ([
                "south"  : __DIR__"main-03s2",
                "north"  : __DIR__"main-03",
                "east"   : __DIR__"main-03se1",
        ]));

        setup();

        replace_program(ROOM);
}