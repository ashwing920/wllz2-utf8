// dangpu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com
inherit ROOM;

void create()
{
        set("short", "当铺");
        set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子(sign)，柜台后坐着唐老板，一双精明的上上下下打
量着你。
LONG
);
        set("no_sleep_room",1);
        set("no_fight", 1);
        set("item_desc", ([
                "sign" : @TEXT
$CYN$
公平交易

pawn       典当
sell         卖 
buy          买
redeem       赎
value      估价
$NOR$
TEXT
        ]));
        set("objects", ([
                __DIR__"npc/tang" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"nandajie1",
        ]));
        setup();
        replace_program(ROOM);
}
