                                        //Room: wdbl.c 武当柏林
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
        set("short","武当柏林");
        set("long",@LONG
你穿行在一片茂密的柏林中，阴森郁翠，怪石嶙峋，草深没人。不时
地有兔子从你的身边飞跑而过。
LONG
);
        set("objects", ([
               "/d/center/npc/hare" : 2,
        ]));
        set("outdoors", "wudang");
        set("exits",([ /* sizeof() == 1 */
                "northdown": __DIR__"yuzhengong",
                "southup"  : __DIR__"haohanpo",
        ]));
        setup();
        replace_program(ROOM);
}
