// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: wuguanchen.c

inherit ROOM;

void create()
{
        set("short", "金牛武馆一部");
        set("long", @LONG
这里是「金牛武馆」教授一部，师傅陈浒教授如下技能：基本轻功，
基本内功，基本招架，基本拳法，基本杖法，基本棒法。
LONG
);
        set("objects", ([
                __DIR__"npc/chenhu" : 1,
        ]));
        
        set("exits", ([
                "west" : __DIR__"wuguan",
        ]));
        setup();
        replace_program(ROOM);
}
