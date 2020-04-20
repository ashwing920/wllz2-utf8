// liangong-fu.c

inherit ITEM;
#include <ansi.h>

int do_jin(string);
int do_cuo(string);
int do_pao(string);

void create()
{
        set_name(YEL"脏衣服"NOR, ({ "zang yifu", "zang", "yifu", "cloth" }));
        set("long",@LONG
这是一件脏衣服，你可以将它拿去河边浸湿(jin)，然后搓一搓(cuo)，如
果干净了就泡两下(pao)衣服就干净了。
LONG
);
        set("jobnum",0);
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("no_drop", "扔掉它是会挨骂的，还是算了吧。\n");
                set("no_give", "这么脏兮兮的东西，给人不怕笑话吗？。\n");

        }
        setup();
}

void init()
{
        add_action("do_jin", "jin");
        add_action("do_cuo", "cuo");
        add_action("do_pao", "pao");
}

int do_jin(string arg)
{
        object ob, me;
        me = this_player();
        ob = this_object();

        if( !me->query_temp("wash_job"))
                return notify_fail("人家又没请你，你喜欢白干啊？\n");

        if (!environment(me)->query("kunming_job"))
                return notify_fail("这个地方没有水，怎么洗衣服？\n");
        if ( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

        if ((ob->query("jobnum"))== 1 )
                return notify_fail("脏衣服已经浸湿了，开始搓吧。\n");
        if ((ob->query("jobnum"))== 2 )
                return notify_fail("脏衣服已经搓好了，还是泡泡吧。\n");
        if (me->query("jing") < 15 )
                return notify_fail("你已经累了,还是歇会吧。\n");

        message_vision(CYN"$N将脏衣服打开，放到溪水里认真的一点点浸湿了。\n"NOR, me);
        ob->set("jobnum",1);
        me->add("jing", -(5+random(10)));
        return 1;
}

int do_cuo(string arg)
{
        int a;
        object ob, me;

        me = this_player();
        ob = this_object();

        if( !me->query_temp("wash_job"))
                return notify_fail("人家又没请你，你喜欢白干啊？\n");

        if (!environment(me)->query("kunming_job"))
                return notify_fail("这个地方没法洗衣服。\n");
        if ( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");
        else if ((ob->query("jobnum"))== 0 )
                message_vision(HIW"$N将脏衣服没浸湿就搓了起来，想把衣服搓破啊。\n"NOR, me);

        if ((ob->query("jobnum"))== 2 )
                return notify_fail("脏衣服已经搓好了，还是泡泡吧。\n");

        if (me->query("jing")<15)
                return notify_fail("你已经累了,还是歇会吧。\n");


        a = random(100);
        if ( a < 15){
                message_vision(HIC"$N将衣服搓了几下，拿起来看了看，好像干净了。\n"NOR, me);
                ob->set("jobnum",2);
        }
        else {
                message_vision(CYN"$N将脏衣服放到石头上费力的搓了起来，一下、两下。\n"NOR, me);
                me->start_busy(1 + random(1));
        }
        me->add("jing", -(5+random(10)));

        return 1;
}

int do_pao(string arg)
{
        int b;
        object ob, me, ob2;
        me = this_player();
        ob = this_object();

        if( !me->query_temp("wash_job"))
                return notify_fail("人家又没请你，你喜欢白干啊？\n");

        if (!environment(me)->query("kunming_job"))
                return notify_fail("这个地方没法洗衣服。\n");

        if ( this_player()->is_busy() )
                return notify_fail("你上一个动作还没有完成。\n");

        if ((ob->query("jobnum"))==0 || (ob->query("jobnum"))==1)
                return notify_fail("衣服没洗就要泡，着什么急呀。\n");

        if (me->query("jing")< 15)
                return notify_fail("你已经累了,还是歇会吧。\n");


        b = random(100);
        if (b < 15){
                message_vision(HIW"$N一不小心，衣服居然随溪水跑了，唉，算是白洗了。\n"NOR, me);
                me->set_temp("jobcloth",3);
                destruct(ob);
        }
        else
                {
                message_vision(HIG"$N将洗好的衣服泡了泡，这件衣服就洗完了，应该可以拿回去交差了。\n"NOR, me);
                me->set_temp("jobcloth",2);
                ob2 = new("/d/kunming/obj/jobcloth2");
                ob2->move(me);
                destruct(ob);
        }
        me->add("jing", -(5+random(10)));
        return 1;
}
