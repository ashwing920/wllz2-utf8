//make by yixiang

inherit ROOM;

void create()
{
        set("short", "药铺内室");
        set("long", @LONG
这是药铺的内室，密密麻麻的一个个小抽屉里，放的都是一些中草药
。几个伙计正在忙着将手中的零散草药，分配（fenyao）到小抽屉里。
LONG
);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"yaopu",
        ]));
        setup();
}
void init()
{
        add_action("do_fenyao","fenyao");
}
int do_fenyao()
{
        object me;
        me = this_player();
        
        if((int)me->query("qi") < 20)
                return notify_fail("你太累了，别分错药了。\n");

        if((int)me->query_temp("fenyaoover"))
                return notify_fail("你的药已经分完了，快去找老板要报酬吧。\n");

        if(me->is_busy())
                return notify_fail("你还忙着呢！\n");

        if(me->is_fighting())
                return notify_fail("战斗中不能分药。\n");

        if((int)me->query_temp("fenyao")) 
                return notify_fail("你已经在工作了。\n");

        if(!(int)me->query_temp("fenyaobegin"))
                return notify_fail("人家又没请你，你来这里做什么？\n");

        message_vision("$N将袖子一缅，开始小心的挑选药材。\n",me);
        me->add("qi",-10);
        me->set_temp("fenyao",1);
        call_out("del_fenyao",1,me);
        return 1;
}
private void del_fenyao(object me)
{
        if(!me) return;

        me->delete_temp("fenyao");

        if((int)me->query_temp("fenyao_times") > 15) {
                write("你终于完成了任务，人也累坏了，快找老板拿报酬去吧！\n");
                me->set_temp("fenyaoover",1);
                return ;
        }        
        switch(random(5)) {
                case 1: 
                        message_vision("$N分的好仔细呀，还检查了一次。\n",me);
                        me->add("qi",-10); 
                        me->add_temp("fenyao_times",1);
                        break;
                case 2: 
                        message_vision("$N看着手上的药材，想了半天终于还是没有找到该放的地方。\n",me); 
                        me->add("qi",-10);
                        me->add_temp("fenyao_times",-1);
                        me->start_busy(1);
                        break;
                case 3:
                        message_vision("$N累的满头大汗，一不小心却分错了药。\n",me);
                        me->add("qi",-10);
                        me->add_temp("fenyao_times",1);
                        me->start_busy(1);
                        break;
                case 4:
                        message_vision("$N将药材仔细挑选，小心翼翼的放到抽屉里。\n",me);
                        me->add("qi",-10);
                        me->add_temp("fenyao_times",1);
                        break;
                default:
                        message_vision("只见$N随手一扔，药居然刚好扔进药箱，好运气呀。\n",me); 
                        me->add("qi",-10);
                        me->add_temp("fenyao_times",2);
                        break;
        } 
        return;
}
