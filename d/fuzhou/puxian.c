// Room: /d/fuzhou/puxian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "莆仙平原");
        set("long", @LONG
你走在莆仙平原上。这里物产丰饶，人烟稠密，望北就是福州府城了
。往南就进入闽南。
LONG
);
        set("exits", ([
                "north" : __DIR__"zhongzhou",
                "south" : "/d/quanzhou/shanlu1",
        ]));

        set("outdoors", "fuzhou");
        setup();
        replace_program(ROOM);
}

