// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "桃源东街");
        set("long", @LONG
这里是桃源之城的东大街。你走在一条繁忙的街道上，看着操着南腔
北调的人们行色匆匆，许多人都往西边走去，那里有一个热闹的广场。南
边是一家店铺，墙上写着一个大大的“当”字，仔细倾听，可以听到压低
的讨价还价的声音。北边是一家生意兴隆的客栈，门额上悬挂一方横匾，
来自各地的人们进进出出。
LONG
);

        set("outdoors", "taoyuan");
        set("exits", ([
                "east"  : __DIR__"roade2",
                "south" : __DIR__"hockshop",
                "west"  : __DIR__"guangchang",
                "north" : __DIR__"inn",
        ]));
        set("objects",([
                __DIR__"npc/fighter": 2,
                __DIR__"npc/zaolaotou":1,
        ]));
        setup();

        replace_program(ROOM);
}
