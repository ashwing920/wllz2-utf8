//d/kunlun/klt.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "昆仑台");
        set("long", @LONG
这里便是昆仑台了，寒风迎面扑来，你开始觉得冷了。只见满峰是雪
，昆仑山在骄阳下看来亮如纯银，到了夕阳西下时又变得灿烂如黄金。身
当此境，顿觉心旷神怡。
LONG
);
        set("outdoors","kunlun");
        set("exits", ([ /* sizeof() == 2 */
                "southwest" : __DIR__"klsj2",
                "northup" : __DIR__"zwf",
        ]));

        setup();
}
