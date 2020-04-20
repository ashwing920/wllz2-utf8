// qianzhuang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "钱庄");
        set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。
它发行的银票信誉非常好，通行全国，更有童叟无欺的美誉。在对面的墙
上挂了块牌子(paizi)。
LONG );
        set("exits", ([
                "east" : __DIR__"beidajie1",
        ]));
        set("item_desc", ([
                "paizi" : @TEXT

本钱庄提供以下服务：

存钱            deposit  或者 cun
取钱            withdraw 或者 qu
钱币兑换        convert  或者 duihuan
查帐            check   或者 chazhang

TEXT
        ]) );

        set("objects", ([
                __DIR__"npc/qian" : 1
        ]));
        set("no_fight",1);
        setup();
        replace_program(ROOM);
}
