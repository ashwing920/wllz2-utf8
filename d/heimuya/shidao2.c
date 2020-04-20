// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
        set("short", "石道");
        set("long", @LONG
一路上日月教教众把守严密，经过两处山道，来到一处水滩之前，西
面有一道石阶通往水滩。
LONG
);
        set("exits",([
                "westdown" : __DIR__"xingxingtan",
                "south" : __DIR__"shidao",
                "east":   __DIR__"liangting",
        ]));
        set("objects",([
                __DIR__"npc/shashou.c" : 2,
                CLASS_D("riyue")+"/wang" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
