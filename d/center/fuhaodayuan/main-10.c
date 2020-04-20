// main-10.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","杂货房");
        set("long", @LONG
这里是主人家的杂货房，杂货房里堆积了一些柴火等的杂物。光线昏
暗，空气浑浊。透过昏暗的光线，你隐约看见杂货房的角落里放着几把柴
刀。
LONG
);
        set("exits", ([
                "south":  __DIR__"main-07",
        ]));

        setup();
        replace_program(ROOM);
}
