// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: tiduroad1.c

inherit ROOM;

void create()
{
        set("short", "提督街");
        set("long", @LONG
提督街就是因为通往提督府而得名。这一带来往行人很少，做生意的
就更是绝迹了。提督大人好象有甚麽想不开的，派了好多兵在这里守卫，
连江湖人物都不敢轻率踏入。
LONG
);
        set("outdoors", "chengdu");
        set("exits", ([
                "south"  : __DIR__"southroad2",
                "north"  : __DIR__"guangchang",
                "east":    "/d/xingbu/gate",
                "west":    __DIR__"masi",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 3,
        ]));
        
        setup();
        replace_program(ROOM);
}
