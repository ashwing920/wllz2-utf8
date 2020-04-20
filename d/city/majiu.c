// 马厩
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short","马厩");
        set("long",@LONG
这是客店后的马厩，常年供应新鲜草料。扬州民风淳朴，马夫们会把
马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到
客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。 马厩中堆放
著几堆草料，正中有一口泔槽。
LONG);
        set("outdoors","city");
        set("no_fight",1);
        set("no_beg",1);
        set("objects", ([
                 __DIR__"npc/zaohongma": 1,
                 __DIR__"npc/huangbiaoma": 1,
                 __DIR__"npc/ziliuma": 1,
                 __DIR__"npc/mafu": 1,
        ]));
        set("item_desc", ([
        "paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往    桃源城:  ridety  
        北京城:  ridebj
        苏州城:  ridesz
        杭州城:  ridehz
        福州城:  ridefz
        大理城:  ridedl
        襄阳城:  ridexy
        永登城:  rideyd
        伊犁镇:  rideyl
        佛山镇:  ridefs
        峨嵋山:  rideem
        成都城:  ridecd

TEXT]));
        set("exits",([ /* sizeof() == 1 */
        "west"  : __DIR__"kedian",
        ]));
        setup();
        replace_program(ROOM);
}
