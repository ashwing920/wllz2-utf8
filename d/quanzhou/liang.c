// room: liang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{ 
           set("short","密室房梁");
           set("long", @LONG
你现在在密室的房梁上四下观瞧，周围都是些烂木头破砖瓦。突然你
瞟见犄角旮旯处有一件袈裟。
LONG
);
        set("exits", ([
                "down" : __DIR__"mishi",
        ]));       
        set("objects", ([
                __DIR__"obj/jiasha" : 1,
                "/d/xingxiu/npc/snake" :1,
        ]));       
        setup();
        replace_program(ROOM);
}

