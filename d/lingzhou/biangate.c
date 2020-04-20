// Room: /lingzhou/biangate.c
// Java. Sep 21 1998

inherit ROOM;

void create()
{
        set("short", "边门");
        set("long", @LONG
这里是皇宫的边门，供侍卫和内侍们出入之用，宫里所需的东西一
般都由此运入，因为比较偏僻，守卫的卫士也不多。
LONG );
        set("exits", ([
                "east"  : __DIR__"xiaolu3",
        ]));
        set("objects", ([
                __DIR__"npc/gongweishi" : 2,
        ]));
        setup();
}
