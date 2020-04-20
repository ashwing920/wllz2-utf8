// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
        set("short","密道");
        set("long", @LONG
一条十分隐蔽的密道，不过墙壁上却点着油灯，看来经常有人出入。
LONG
);
        set("exits", ([
                "out" : __DIR__"houyuan",
                "west" : __DIR__"midao2",
        ]));
        setup();
        replace_program(ROOM);
}
