//Room: /d/dali/nongtian5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","农田");
        set("long",@LONG
这是一小块普通的水田，附近有溪流流过，灌溉十分方便。围绕农田
的是一片片桑林，摆夷人采桑、养蚕，纺织相当精致的丝织品。西边有所
民居。
LONG
);
        set("objects", ([
                __DIR__"npc/nongfu2": 1,
                __DIR__"npc/cow": 1,
        ]));
        set("outdoors", "dali");
        set("exits",([ /* sizeof() == 1 */
                "south"  : __DIR__"buxiongbu",
                "east"   : __DIR__"langan3",
        ]));
        setup();
        replace_program(ROOM);
}

