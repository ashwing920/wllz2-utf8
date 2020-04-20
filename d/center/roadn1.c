  // roadn1.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "桃源北街");
        set("long", @LONG
这里是桃源城的北大街。你走在一条繁忙的街道上，看着操着南腔北
调的人们行色匆匆，许多人都往南边走去，那里有一个热闹的广场。东边
是一家生意兴隆的客栈，门额上悬挂一方横匾，来自各地的人们进进出出
。西边是桃源城里人气最旺，最负盛名的英雄楼了。
LONG
);

        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"inn",
                "south" : __DIR__"guangchang",
                "west"  : __DIR__"yingxionglou",
                "north" : __DIR__"roadn2",
        ]));
        setup();
        replace_program(ROOM);
}
