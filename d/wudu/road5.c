// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
        set("short","柳林");
        set("long", @LONG
你走在一片柳树林中，微风吹的树页沙沙响，好比一首美妙的曲子另
人不由精神一震，前面是一座阁楼。
LONG
);
        set("outdoors", "wudu");
        set("exits", ([
                "west" : __DIR__"daguanlou",
                "east" : __DIR__"road4",
        ]));
        setup();
        replace_program(ROOM);
}

