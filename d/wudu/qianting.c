// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","前厅");
        set("long", @LONG
这里是五毒神教的前厅，看上去十分的简陋，既无雕龙画凤，也金砖
玉瓦，四壁徒空。却又透着一股子邪气。东边通向五毒神教弟子休息练功
的地方，西边是厨房。北面是五毒大厅。
LONG
);
        set("valid_startroom", 1);
        set("exits", ([
                "west" : __DIR__"chufang",
                "east" :__DIR__"zoulang",
                "north" :__DIR__"dating",
                "southdown" :__DIR__"taijie"
        ]));
        set( "objects", ([
                CLASS_D("wudu") + "/qiyun" : 1,
                CLASS_D("wudu") + "/master_wudu" : 1,
        ]));
        setup();
        "/clone/board/wudu_b"->foo();
        replace_program(ROOM);
}
