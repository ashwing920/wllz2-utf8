#include <room.h>

inherit ROOM;

void create()
{
        set("short", "当铺");
        set("long", @LONG
这里是桃源之城的当铺。这是一家以公平买卖著称的当铺，一个五尺
高的柜台挡在你的面前，柜台上摆着一个木牌(sign)。柜台后面，一双精
明的眼睛在上上下下打量着你。
LONG
);

        set("item_desc", ([
                "sign": @TEXT

本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
本当铺提供以下服务：

    查询        list
    买进        buy
    卖断        sell
    估价        value
    典当        pawn
    赎回        ransom

各种货物，铜钱、银两、黄金、银票一概通用。

TEXT
]));

        set("exits", ([
                "west"  : __DIR__"roads1",
                "north" : __DIR__"roade1",
        ]));

        set("objects", ([
                __DIR__"npc/hockman" : 1,
        ]));
        set("no_fight",1);
        setup();
        replace_program(ROOM);
}
