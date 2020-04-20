// roadn3.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","桃源北街");
        set("long", @LONG
你走在北大街上，踩着坚实的青石板地面，西边是桃源城里最出名的
一间澡堂--华清池，许多名门贵族和达官贵人，都经常到华清池来。大街
东面有一家武馆，不时从武馆传来一阵阵喝哈声。想必是武馆的弟子们在
练功吧！
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"wuguan",
                "south" : __DIR__"roadn2",
                "west"  : __DIR__"bathhouse",
                "north" : __DIR__"roadn4",
        ]));
        set("objects", ([
                "/d/city/npc/polan": 1,
	]));
        setup();
        replace_program(ROOM);
}
