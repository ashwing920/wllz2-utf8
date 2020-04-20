//Room: /d/dali/wangfugate.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","王府大门");
        set("long",@LONG
你正站在一座豪华的府门前，门前有两只极大的石狮子，门上高悬一
块横匾，上书「镇南王府」四个金字。门口站着两排侍卫，身着锦衣，手
执钢刀，气宇轩昂。
LONG
);
        set("objects", ([
                CLASS_D("dali")+"/zhuwanli": 1,
                __DIR__"npc/weishi2": 1,
                __DIR__"npc/weishi1": 2,
                CLASS_D("dali")+"/master_dali": 1,
        ]));
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
                "enter"  : __DIR__"wfdating",
                "south"  : __DIR__"wangfulu",
        ]));
        setup();
        "/clone/board/dali_b"->foo();
}

