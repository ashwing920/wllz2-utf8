// guanfu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "官府大堂");
        set("long", @LONG
你来到了官府大堂之上，只见大堂上方挂着一块牌匾，上面写着：光
明正大四个大字。大堂上有一张书案，是平常巡岸大人批示公文，审理案
件的地方。大堂两边，站着几个官差，手持木棍，一丝不苟的站立着。一
片威严之势，让人不得不肃然起敬。
LONG
);
        set("exits", ([
                "south":  __DIR__"guanfu-1",
        ]));
        set("objects", ([
                __DIR__"npc/zhang":1,
                "/d/city/npc/yayi":4,
        ]) );
        setup();
        set("no_fight",1);
        set("no_kill",1);
        set("no_beg",1);
        set("no_steal",1);
        replace_program(ROOM);
}
