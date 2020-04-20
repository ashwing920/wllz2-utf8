// Room: /d/suzhou/road5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆
而过。北面就是苏州城了。西南边远远望去，波光粼闪，白帆点缀，便是
周遭五百里的太湖了。
LONG
);
        set("outdoors", "suzhou");
        set("exits", ([
                "north"  : __DIR__"nanmen",
        ]));
        setup();
        replace_program(ROOM);
}
