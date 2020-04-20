// main-09.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","厨房");
        set("long", @LONG
这里是富豪大院的厨房，一个半人高的灶头筑在厨房的墙边。一个年
越六旬的老者正在灶头边上做菜，看来是快到开饭的时候了，一股饭菜喷
香扑鼻而来。厨房的西边角落里放着一张残旧的大木桌，上面放着一些碗
筷还没有洗呢！
LONG
);
        set("exits", ([
                "west":  __DIR__"main-07",
        ]));
        set("objects", ([
                __DIR__"npc/huotou" : 1,
        ]));

        setup();
}
void init()
{
        add_action("do_xi","xi");
}

int do_xi(string arg)
{

        object me;
        int times;
     
        me = this_player();
        
        if(!arg || arg!="碗")
                return notify_fail("你要干什么？\n");
    
        if (me->is_fighting())return notify_fail("边洗碗边打架？你是神仙呀？！\n");
        if (me->is_busy()) return notify_fail("你正忙着呢！！\n");
        if ( me->query("qi") < 20 || me->query("jing") <= 20) return notify_fail("你太累了，还是休息一下吧！\n");
        if (me->query_temp("working")) return notify_fail("你已经在洗碗了！\n");
        if (me->query_temp("wash_finish") >= 1) return notify_fail("这里碗都洗干净了，快去交差吧！\n");
        if (me->query_temp("wash_job")!= 1) return notify_fail("人家又没有请你，你喜欢白干呀？\n"); 

        times = 10 + random(5);

        if ((int)me->query_temp("job_times") > times ){
        tell_object(me,"碗已经洗好了，你终于完成了任务，人也累坏了。\n");
        me->set_temp("wash_finish",1);
        return 1;
        }                     

        me->set_temp("working",1);
        message_vision("$N拿着一条抹布，轻轻的擦拭着瓷碗。\n",me);
        call_out( "compelete_wash", 1, me );
        me->start_busy(1);
        return 1;
}
private void compelete_wash(object me)
{
        if (random(50) == 25){
                message_vision("$N一不小心，把手中的碗全部打翻了。\n",me);
                me->add("qi",- random(5));
                me->delete_temp("working");
                return;
        }
        if (random(100) > 60){
                message_vision("$N一不小心，瓷碗跌落在地，应声碎做两半。\n",me);
                me->add("jing",- random(10));
                me->add("qi",- random(10));
                me->delete_temp("working");
                return;
        }

        if( present(me) ) {                    
                message_vision("$N显得十分勤快，把瓷碗洗得干干净净。\n", me);
                me->delete_temp("working");
                me->add("qi", - 10);
                me->add("jing",- 10);
                me->add_temp("job_times",1);
                me->add("all_job_times",1);
                return;
        }

        return;
}
