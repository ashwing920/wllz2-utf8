//room: /d/btshan/restroom.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short","休息室");
        set("long",@LONG
这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能打扰
。南面是气派的长廊。
LONG
);
        set("exits",([
                "south" : __DIR__"changlang",
        ]));

        set("sleep_room", 1);
        setup();
        replace_program(ROOM);
}
