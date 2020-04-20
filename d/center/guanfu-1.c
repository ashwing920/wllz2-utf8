// guanfu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "官府前堂");
        set("long", @LONG
你跨进桃源官府的前堂，只见前堂两边竖立着几个牌匾，上面分别写
着“肃静”、“回避”等，显得十分庄严。牌匾前站着几个巡捕和衙役，
似乎在谈论着些什么。
LONG
);
        set("outdoors", "taoyuan");
        set("exits", ([
                "north":  __DIR__"guanfu-2",
                "south":  __DIR__"guanfu",
        ]));
        set("objects", ([
                "/d/city/npc/yayi": 2,
                "/clone/npc/xunbu":2,
        ]) );
        setup();

        replace_program(ROOM);
}
