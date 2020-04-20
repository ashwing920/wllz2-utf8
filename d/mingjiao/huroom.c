// huroom.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "医居");
        set("long", @LONG
你走进了烈火旗的大院后进，这里是个很宁静的小屋。四周摆了不少
医学典籍，还有很多散落堆放的膏、丸、散等。一个老头在此呆呆出神，
似乎有无限心事。
LONG
);
        set("exits", ([
                "out"    : __DIR__"lhqyuan",
        ]));
        set("objects", ([
                __DIR__"npc/hu" : 1,
        ]));
        set("outdoors", "mingjiao");
        setup();
        replace_program(ROOM);
}
