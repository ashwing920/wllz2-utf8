// up-01n1w.c - 千金楼（厢房）

inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
这里是千金楼二楼一间普通的厢房。厢房里收拾得十分干净，一张大
床陈列在厢房的右侧，床上挂着一廉粉红色的床帘，十分好看。厢房中央
有一张八仙桌，一个青楼女子正在旁边低头沉思，象是在思念些什么。
LONG
);
        set("sleep_room",1);
        set("exits", ([
                "east" :  __DIR__"up-01n1",
        ]));
        set("objects", ([
                __DIR__"npc/mingji-i": 1,
                __DIR__"npc/yahuan": 1,
                __DIR__"npc/lishishi":1,
        ]) );
        setup();
        replace_program(ROOM);
}
