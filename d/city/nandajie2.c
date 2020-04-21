// nandajie.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
inherit ROOM;

void create()
{
        set("short", "南大街");
        set("long", @LONG
你走在一条繁华的街道上，向南北两头延伸。南边是南城门，北边通
往市中心，西边是一家顾客众多的茶馆，三教九流人士都在那里谈天说地
。东边一座两层的楼房传来阵阵浪笑，那就是天下闻名的丽春院。
LONG
);
        set("outdoors", "city");
        set("exits", ([
                "east"  : __DIR__"lichunyuan",
                "south" : __DIR__"nanmen",
                "west"  : __DIR__"chaguan",
                "north" : __DIR__"nandajie1",
        ]));
        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
                "/d/dali/npc/duanyu":1,
                "/clone/npc/langzhong": 1,
        ]));
        setup();
        replace_program(ROOM);
}