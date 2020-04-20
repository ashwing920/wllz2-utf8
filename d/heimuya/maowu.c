// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
        set("short", "茅草屋");
        set("long", @LONG
这是一间搭建在山边的茅草屋，屋里陈设十分简单，只有靠边的一张
小木床，是让在日月神教弟子守卫山门轮侯休息用的。
LONG
);
        set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"shimen",
        ]));
        setup();
        replace_program(ROOM);
}
