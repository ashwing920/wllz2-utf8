//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: fhs.c 伏虎寺

inherit ROOM;

void create()
{
        set("short","伏虎寺");
        set("long",@LONG
伏虎寺是入山第一大宝刹，隐伏在高大的乔木林间，四周楠木参天，
多达十万余株。伏虎寺气象庄严，规模宏盛，殿堂宽敞，势度巍峨。寺刹
虽掩覆于翠绿浓黛之中，但屋瓦却无一片落叶。出寺西上解脱坡便是观音
堂。
LONG
);
        set("objects", ([
                __DIR__"npc/boydizi" : 1,
                __DIR__"npc/girldizi" : 1,
                CLASS_D("emei")+"/master_emei": 1,
        ]));
        set("exits",([
                "east"  : __DIR__"milin1",
                "westup"  : __DIR__"milin2",
        ]));
        set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
