// Room: /huanghe/weifen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "渭汾流域");
        set("long", @LONG
汾河和渭河汇入黄河，增大了其水势，也带来了更多的泥沙。这里河
东是晋，河西是陕。
LONG
);
        set("exits", ([
                "south" : __DIR__"huanghe1",
                "north" : __DIR__"huanghe_1",
        ]));
        set("outdoors", "huanghe");
        setup();
        replace_program(ROOM);
}

