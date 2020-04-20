// Room: /d/henshan/hengyang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "衡阳城");
        set("long", @LONG
这里就是衡阳县城。衡阳地处偏远，显见远不如中原繁华了。
LONG
);
        set("outdoors", "henshan");
        set("exits", ([
                "east"   : __DIR__"hsroad3",
                "west"   : __DIR__"hengyang1",
                "south"  : __DIR__"chaguan",
                "north"  : __DIR__"lingxingmen",
        ]));
        set("objects", ([
                __DIR__"npc/lu" : 1,
                "/clone/npc/xunbu": 5,
        ]));
        setup();
        replace_program(ROOM);
}
