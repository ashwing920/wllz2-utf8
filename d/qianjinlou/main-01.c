// main-01.c - 千金楼（大厅）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
你来到了千金楼的大厅，只见大厅装饰豪华奢侈：地面铺设着金边的
红色地毯，四面金碧辉煌。北面还有一排挂钟，几个青楼女子正在弹奏歌
乐。大厅中间坐着几个身着华贵的男子，想必是来这里寻欢的吧！大厅旁
边有条楼梯，通往千金楼二楼。
LONG
);
        set("exits", ([
                "east"  : __DIR__"main-02",
                "west"  : "/d/center/jiyuan",
                "up"    : __DIR__"up-01",
        ]));

        set("objects", ([
                __DIR__"npc/mother": 1,
                __DIR__"npc/mingji": 1,
                __DIR__"npc/mingji-a": 1,
                __DIR__"npc/jinu": 2,
                __DIR__"npc/guinu": 1,
                __DIR__"npc/piaoke":2,
	]) );

        setup();

        replace_program(ROOM);
}