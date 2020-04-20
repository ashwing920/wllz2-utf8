            // Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: wuguanchen.c

inherit ROOM;

void create()
{
        set("short", "金牛武馆二部");
        set("long", @LONG
这里是「金牛武馆」教授二部，师傅龙铨教授如下技能：基本轻功，
基本内功，基本招架，基本爪法，基本刀法。
LONG
);
        set("objects", ([
                __DIR__"npc/longquan" : 1,
        ]));
        
        set("exits", ([
                "north" : __DIR__"wuguan",
        ]));
        setup();
        replace_program(ROOM);
}
