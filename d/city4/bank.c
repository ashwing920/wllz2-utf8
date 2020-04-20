                          //Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","相记钱庄");
        set("long",@LONG
这是一家老字号的钱庄，相老板是山西人，这家钱庄从他的爷爷的爷
爷的爷爷的爷爷那辈开始办起，一直传到他手里，声誉非常好，在全国各
地都有分店。它发行的银票通行全国。钱庄的门口挂有一块牌子(paizi)。
LONG
);
        set("item_desc", ([
                "paizi": @TEXT
这里是钱庄，目前我们提供的服务有：

check            查帐
deposit          存款
withdraw         取款
convert          兑换钱币。

TEXT
        ]));
        set("exits", ([
                "north" : __DIR__"center",
        ]));
        set("objects", ([
                __DIR__"npc/tiesuanpan" : 1,
        ]));
        set("no_fight",1);
        setup();
        replace_program(ROOM);
}
