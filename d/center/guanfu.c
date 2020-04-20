// guanfu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "官府门口");
        set("long", @LONG
这里是桃源城中最威严的地方--桃源城官府。你站在官府门口，门口
两边各有两个官兵手持钢刀，紧紧的把守着，不时盯着过路的行人一眼，
显得十分警惕。官兵身后有一个大皮鼓，是给告状申冤的百姓们用的。一
片威严冷峻之势，让人不得不肃然起敬。
LONG
);
        set("outdoors", "taoyuan");
        set("exits", ([
                "south":  __DIR__"roade2",
                "north":  __DIR__"guanfu-1",
        ]));

        set("objects", ([
                "/d/city/npc/yayi": 4,

        ]) );

        setup();

        replace_program(ROOM);
}
