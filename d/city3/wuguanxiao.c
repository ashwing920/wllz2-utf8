// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: wuguanxiao.c

inherit ROOM;

void create()
{
        set("short", "金牛武馆三部");
        set("long", @LONG
这里是「金牛武馆」教授三部，师傅萧飞教授如下技能：基本轻功，
基本内功，基本招架，基本指法，基本暗器。
LONG
);
        set("objects", ([
                __DIR__"npc/xiaofei" : 1,
        ]));
        
        set("exits", ([
                "east" : __DIR__"wuguan",
        ]));
        setup();
        replace_program(ROOM);
}
