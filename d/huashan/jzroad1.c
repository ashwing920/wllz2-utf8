// Room: /d/huashan/jzroad1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "松树林");
        set("long", @LONG
这是一片松树林。中间一条小路，两边都是黑森森的几丈高的松树。
树上结着不少松果，间或有野兔游悠游而过。
LONG
);
        set("exits", ([
                "southwest" : "/d/village/hsroad2",
                "east"    : __DIR__"jzroad2",
        ]));
        set("objects", ([
                "/d/center/npc/hare": 3,
        ]));
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

