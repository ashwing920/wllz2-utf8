// yaochu.c  药锄

#include <weapon.h>

inherit STAFF;

string *can_find = ({"树林","草地","竹","山道",});
string *yaocai = ({
        "/clone/drug/jinyinhua",
        "/clone/drug/tuoluohua",
        "/clone/drug/yangjinhua",
        "/clone/drug/honghua",
        "/clone/drug/yueju",
        "/clone/drug/baishu",
        "/clone/drug/gancao",
        "/clone/drug/shecao",
        "/clone/drug/jinqiancao",
        "/clone/drug/heshouwu",
        "/clone/drug/shanshen",
        "/clone/drug/duanxuecao",
});

void create()
{
        set_name("药锄", ({ "yaochu","chu" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把用来采药的锄头，入手轻轻的，似乎不是相当结实。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放下。\n");
        }
        init_staff(25);
        setup();
}

void init()
{
        if(environment() == this_player())
        add_action("do_bo","bo");
}
int do_bo(string arg)
{
        object me,ob,obj;
        string long;

        me = this_player();

        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");

        if(me->query("jing") < 60
        || me->query("qi") < 60)
                return notify_fail("你现在精神不好，还是歇一下再说吧！\n");

        if(me->query("family/family_name") != "全真教")
                return notify_fail("这把药锄你是从哪弄来的？\n");

        if(!environment(me)->query("outdoors"))
                return notify_fail("你想在这里拨些什么呀？\n");

        if (!objectp(ob = me->query_temp("weapon"))
                || (string)ob->query("id") != "yaochu")
                return notify_fail("没有药锄怎么拨杂草呢？\n");

        long = environment(me)->query("short");
        if( member_array(long,can_find) == -1) {
                message_vision("$N手挥药锄在这里拨了大半天，却什么也没找到。\n",me);
                me->start_busy(1);
                return 1;
        }

        if(ob->query("use_time") > 15 + random(20)){
                tell_object(me,"只听见“啪”的一声，药锄断开两半。\n");
                destruct(ob);
                return 1;
        }

        switch(random(10)){
                case 1:
                        message_vision("$N挥动着药锄非常卖力地拔开着杂草，可惜什么也没有发现！\n",me);
                        me->start_busy(1);
                        break;
                case 2:
                        message_vision("$N挥动着药锄非常卖力地拔开着杂草，却发现杂草堆里什么都没有！\n",me);
                        me->start_busy(1);
                        break;
                case 3:
                        obj = new(yaocai[ random(sizeof(yaocai))]);
                        obj->move(me);
                        message_vision("$N挥动着药锄拨开杂草，发现了一棵$n，连忙用药锄砍了下来。\n",me,obj);
                        me->start_busy(1);
                        break;
                case 4:
                        obj = new("/d/shenlong/npc/dushe");
                        message_vision("$N挥动着药锄拨开杂草，却发现了一条吐着红信子的$n。\n",me,obj);
                        obj->move(environment(me));
                        obj->kill_ob(me);
                        me->kill_ob(obj);
                        break;
                default:
                        message_vision("$N挥动着药锄非常卖力地拔开着杂草，可惜什么也没有发现！\n",me);
                        me->start_busy(1);
                        break;
        }
        ob->add("use_time",-1);
        me->receive_damage("qi",50);
        me->receive_damage("jing",50);
        return 1;
}
