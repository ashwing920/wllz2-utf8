// roadw3.c - 西大街
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "桃源西街");
        set("long", @LONG
你走在桃源城的西大街上，踩着坚实的青石板地面。南边有一家药店
，出售一些珍贵的中草药。北面是一家书院，站在这里，不时可以听见从
书院里传来阵阵朗朗的读书声。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"roadw2",
                "south" : __DIR__"yaodian",
                "west"  : __DIR__"roadw4",
                "north" : __DIR__"shuyuan",
        ]));
        set("objects", ([
                __DIR__"npc/drunk": 1,
                "/d/city/npc/polan": 1,
        ]) );
        setup();
        replace_program(ROOM);
}
