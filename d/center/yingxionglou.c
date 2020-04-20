// yingxionglou.c

inherit ROOM;

void create()
{
        set("short","英雄楼");
        set("long",@LONG
这里是桃源城里极负盛名的英雄楼，只见英雄楼足有四层楼高，经常
是一些江湖侠客、英雄好汉们聚集的地方。英雄楼楼中，经常可以看见来
自五湖四海的英雄豪客，在这里把酒言欢。确实是个打探江湖中留言、传
闻的好地方。
LONG
);
        set("exits",([
                "east": __DIR__"roadn1",
                "south": __DIR__"roadw1",
                "up":  __DIR__"chat_room",
        ]));
        set("objects",([
                "/d/city/npc/jiayi":1,
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        set("restrict_action",1);
        setup();
        call_other("/clone/board/taoyuan","??");
}
int valid_leave(object me, string dir)
{
        if( dir == "up" && (!userp(me) || me->query_condition("killer") 
        || me->query_condition("f_killer")))
                return notify_fail("那里不是你能去的地方。\n");
        return ::valid_leave(me, dir);
}
