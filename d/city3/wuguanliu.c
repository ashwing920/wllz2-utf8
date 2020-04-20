// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: wuguanliu.c

inherit ROOM;

void create()
{
        set("short", "金牛武馆四部");
        set("long", @LONG
这里是「金牛武馆」教授四部，师傅刘虹瑛教授如下技能：基本轻功
，基本内功，基本招架，基本掌法，基本剑法。
LONG
);
        set("objects", ([
                __DIR__"npc/liuhongying" : 1,
        ]));
        
        set("exits", ([
                "south" : __DIR__"wuguan",
        ]));
        setup();
        replace_program(ROOM);
}
