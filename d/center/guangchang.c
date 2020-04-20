// guangchang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>;

inherit ROOM;

void create()
{
        set("short", "桃源之城");
        set("long", @LONG
这里是桃源之城的正中心，一个很宽阔的广场，地面整齐地铺着大青
石板。一些武林侠士经常聚集在这里。广场中央是一座十数人高的汉白玉
图腾，上面刻看四个金色的大字“桃源之城”。图腾周围的一片都是花儿
草儿，附近有几棵大榕树，盘根错节，据传已有千年的树龄，是这座城市
的历史见证。你可以看到四面都有来自各地的行人来来往往，人声鼎沸，
一派繁华景象。
LONG
);
        set("valid_startroom", 1);
        set("outdoors", "taoyuan");
        set("objects",([
                "/clone/npc/mingbu": 1,
                "/clone/npc/xunbu": 3,
        ]));
        set("item_desc", ([
                "sign": @TEXT
$HIM$

    桃  源  之  城

$NOR$
TEXT
        ]));

        set("exits", ([
                "east"  : __DIR__"roade1",
                "south" : __DIR__"roads1",
                "west"  : __DIR__"roadw1",
                "north" : __DIR__"roadn1",
        ]));
        setup();
        replace_program(ROOM);
}

