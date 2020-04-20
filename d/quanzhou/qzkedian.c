// Room: /city/kedian.c

inherit ROOM;

void create()
{
        set("short", "鸿福楼");
        set("long", @LONG
这是泉州城中字号最老的客栈蒹酒楼，生意非常兴隆。许多江湖人物
在这里高谈阔论，所以这里是个打听到情报的好地方。墙上挂着一个牌子
(paizi)。东面是一间马厩。
LONG
);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : "楼上雅房，每夜四两白银。\n",
        ]));
        set("objects", ([
                __DIR__"npc/qzxiaoer" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"citong_n3",
                "up" : __DIR__"qzkedian2",
        ]));
        set("outdoors", "quanzhou");
        setup();
}

int valid_leave(object me, string dir)
{
        if(!me->query_temp("rent_paid")
        && dir == "up"
        && present("xiao er", environment(me)))
                return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

        if(me->query_temp("rent_paid")
        && dir != "up"
        && present("xiao er", environment(me)))
                me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}
