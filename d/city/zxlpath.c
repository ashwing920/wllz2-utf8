                                      // zxlpath.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "醉仙楼大堂");
        set("long", @LONG
这是醉仙楼大堂，来来往往的人客和跑堂小二，夹杂着三个宴会厅刺
耳的呼叫声，碰杯声，打闹声，赖酒声，热闹非凡。你在三个宴会厅前打
量着进哪个凑个热闹，蹭点白食。东边是玫瑰厅，朝南的是牡丹厅，向北
是芙蓉厅。
LONG);
        set("exits", ([
                "east"   : __DIR__"meigui",
                "north"  : __DIR__"furong",
                "south"  : __DIR__"mudan",
                "west"   : __DIR__"zuixianlou2",
                "up":      __DIR__"yanhui",
        ]));
        setup();
        replace_program(ROOM);
}
