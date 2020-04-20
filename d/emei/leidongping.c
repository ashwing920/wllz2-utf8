//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: leidongping.c 雷洞坪

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","雷洞坪");
        set("long",@LONG
雷洞坪一带，道路艰险骇人，路左是蔽日遮天的冷杉林，路右是深不
见底的绝壁峡谷。这里长年云遮雾罩，空蒙黑暗。岩上建有雷神殿，旁边
竖一铁碑。由此往上是「八十四盘」至接引殿，北下到洗象池。
LONG
);
        set("outdoors", "emei");
        set("exits",([ 
                "northdown"  : __DIR__"lingyunti",
                "southup"       : __DIR__"bashisipan1",
                "east"     : __DIR__"lengsl1",
        ]));

        setup();
}

void init()
{
        add_action("do_say","say");
}
int do_say()
{
        object me;
        int qi_cost,jing_cost,c_exp,c_skill;
        me = this_player();
        c_exp=me->query("combat_exp");
        c_skill=me->query_skill("force",1);
        qi_cost = 10+c_skill/2+random(c_skill/2);
        jing_cost = qi_cost/4+random(qi_cost/4);

        if(me->query("qi")>qi_cost+2 && me->query("jing")>jing_cost+2) {
                message_vision(CYN"$N刚说出一个字，刹那间惊雷迅电，霹雳而作，风雨暴来。\n"NOR, me);
        if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101)){
                me->improve_skill("force", qi_cost+jing_cost);
                me->add("qi",-qi_cost);
        }
}
        else
                {
        message_vision(CYN"$N刚说出一个字，刹那间惊雷迅电，霹雳而作，风雨暴来。\n$N一下子被打中，全身发麻。\n"NOR, me);
        me->unconcious();
}
        return 1;
}

int valid_leave(object me, string dir)
{
        int c_exp,c_skill;
        me = this_player();
        if (dir == "southup" ){
        c_exp=me->query("combat_exp");
        c_skill=me->query_skill("dodge",1);
        me->add("qi",-10);
        if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_exp< 101))
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
        tell_object(me,"你爬上八十四盘，有些累了。\n");
}
        return 1;
}
