// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","桃源东街");
        set("long", @LONG
你走在桃源之城的东大街上，踩着坚实的青石板地面。南边有一家打
铁铺，不时从打铁铺里传来阵阵“叮当”的声响。北面是一家百货，出售
一些生活用品。
LONG
);
        set("outdoors", "taoyuan");
        set("exits", ([
                "east"  : __DIR__"gatee",
                "south" : __DIR__"datiepu",
                "west"  : __DIR__"roade3",
                "north" : __DIR__"zahuopu",
        ]));
        setup();
	replace_program(ROOM);
}
