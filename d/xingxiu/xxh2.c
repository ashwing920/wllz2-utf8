// Room: /d/xingxiu/xxh2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海边。说是海，其实是片湖泊和沼泽，地形十分险恶。这
里左右两厢通向星宿海的深处，南边是星宿派总舵——日月洞。洞口立着
一个牌子(paizi)。
LONG
);
        set("exits", ([
                 "north" : __DIR__"riyuedong",
                 "south" : __DIR__"xxh1",
                 "northeast" : __DIR__"xxh3",
                 "northwest" : __DIR__"xxh4",
        ]));

        set("valid_startroom",1);
        set("item_desc", ([
                "paizi" : "星宿海福地，日月洞洞天。\n",
        ]));
        set("objects", ([
                CLASS_D("xingxiu")+"/tianlang" : 1,
                CLASS_D("xingxiu")+"/master_xingxiu" : 1,
        ]) );

        set("outdoors", "xingxiuhai");
        setup();
        "/clone/board/xingxiu_b"->foo();

}
