// roads7.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "桃源南街");
        set("long", @LONG
你走在桃源城的南大街，大街宽敞非常，两旁店面林立，出售的多数
是一些日用品和当地的有名小食。站在这里，你可以看见南面有一扇红漆
大门，大门上方挂着一块大牌匾，上面写着：竞技场三个大字。门口两边
各有一头石狮，显得十分庄严威武。
LONG
);
        set("outdoors","taoyuan");
        set("exits", ([
                "north" : __DIR__"roads6",
                "south":  __DIR__"jingjichang",
                "east":  __DIR__"taolunshi",
                "west": "/d/daochang/daochang_gate",
        ]) );
        setup();
        create_door("south","红漆大门","north",DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
        if( dir == "south" 
        	&& (me->query_condition("killer") || me->query_condition("f_killer")))
                return notify_fail("你迟疑了一会，心想：比武擂台可是公众场所，还是小心为妙。\n");
        return ::valid_leave(me, dir);
}
