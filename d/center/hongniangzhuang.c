// hongniangzhuang.c - 红娘庄
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "红娘庄");
        set("long", @LONG
这里是桃源城的红娘庄，这里是专门替人缔结婚约和解除婚约的地方
，城里所有的夫妇都是在这里喜结良缘的，就连附近城市也有许多慕名而
来的。靠近门口的地方有一块乌木雕成的招牌(sign)。
LONG
);

        set("exits", ([
                "east"  : __DIR__"dahuaishu",
                "west"  : __DIR__"xiaosonglin",
        ]) );                   
        set("no_fight",1);
        set("item_desc", ([
                "sign": @TEXT
红娘庄免费提供以下服务：：
$CYN$
marry       缔结姻缘
unmarry     解除婚约
$NOR$
TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/meipo" : 1 ,
                __DIR__"npc/hongniang" : 1 ,
        ]));
        setup();

        replace_program(ROOM);
}
