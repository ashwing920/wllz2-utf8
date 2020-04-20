// 马厩
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short","马厩");
        set("long",@LONG
这是成都的马厩，常年供应新鲜草料。成都民风淳朴，马夫们会把马
牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客
人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。 马厩中堆放著
几堆草料，正中有一口泔槽。
LONG);
        set("outdoors","city3");
        set("no_fight",1);
        set("no_beg",1);
        set("objects", ([
                 "/d/city/npc/zaohongma": 1,
                 "/d/city/npc/huangbiaoma": 1,
                 "/d/city/npc/ziliuma": 1,
                 __DIR__"npc/mafu": 1,
        ]));
        set("item_desc", ([
        "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz

TEXT
]));
        set("exits",([
                "east"  : __DIR__"tiduroad",
        ]));
        setup();
        replace_program(ROOM);
}
