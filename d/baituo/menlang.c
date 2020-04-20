//room: menlang.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short","门廊");
        set("long",@LONG
这是个门廊，门廊的飞檐上挂着一串串的小铜铃，在清风中发出清脆动听
的铃声。
LONG
);
        set("exits",([
                "north" : __DIR__"huayuan",
                "south" : __DIR__"liangong",
        ]));
        set("objects",([
                __DIR__"npc/guanjia" : 1,
                CLASS_D("btshan")+"/master_btshan": 1,
        ]));

        set("outdoors","baituo");
        setup();
        replace_program(ROOM);
}
