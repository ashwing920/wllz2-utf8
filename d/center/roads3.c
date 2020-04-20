// roads3.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short", "桃源南街");
        set("long", @LONG
你走在桃源城的南大街上，踩着坚实的青石板地面。这里没有城中心
那般热闹，人群也稀疏了许多，只有偶尔几个游客或居民经过。西边是一
家花店，阵阵鲜花的清香扑鼻而来，令人陶醉。东面是一家竹器店，出售
一些竹制的用品。
LONG
);

        set("outdoors", "center");
        set("exits",([
                "west"  : __DIR__"huadian",
                "south" : __DIR__"roads4",
                "east"  : __DIR__"zhuqipu",
                "north" : __DIR__"roads2",
        ]));

        set("objects", ([
                "/d/city/npc/polan": 1, 
                __DIR__"npc/beggar":1,
	]) );
        setup();
        replace_program(ROOM);
}
