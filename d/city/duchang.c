// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "赌场");
        set("long", @LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。西边是
赌「大小」的房间，北边是赌「牌九」的房间(建设中)，南面是闽南特有
的搏饼娱乐间。墙上显眼处挂着一块牌子(paizi)。
LONG );
        set("item_desc", ([
                "paizi" : "二楼的拱猪房正处于测试阶段。\n",
        ]));
        set("objects", ([
                CLASS_D("shenlong")+"/pang" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"daxiao",
                "up"   : __DIR__"duchang2",
                "east" : __DIR__"nandajie1",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}
