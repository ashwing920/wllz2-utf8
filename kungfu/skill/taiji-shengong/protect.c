// protect.c

#include <ansi.h>

void remove_effect(object me);

int exert(object me, object target)
{
        int double_skill;
        int delay;

        if( target != me ) 
                return notify_fail("护体真气只能用来保护你自己。\n");
        if( (int)me->query("neili") < 100 ) 
                return notify_fail("你的内力不够。\n");
        if( me->query_temp("protect") ) 
                return notify_fail("你已经在运功中了。\n");

        double_skill = (int)me->query_skill("taiji-shengong");
        delay = (int)me->query_skill("force");
        me->add("neili", -100);
        message_vision(HIW + BLK"$N气沉丹田，深吸了一口气，太极神功的护体真气。$N顿时衣袖鼓风飘起，便如风帆一般！\n"NOR,me);

        me->set_temp("protect", double_skill);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), delay);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me)
{
        if(!me) return;
        if (me->query_temp("protect") ){ 
                me->delete_temp("protect");
                message_vision("$N的太极神功运行完毕，缓缓地将内力收回了丹田。\n", me);
        }
}
 
int clean_up()
{
        return 1;
}
void reset()
{
}
