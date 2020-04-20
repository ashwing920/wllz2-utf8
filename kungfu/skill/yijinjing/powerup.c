// powerup.c 易筋经加力

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;

        if( target != me )
                return notify_fail("你只能提升自己的战斗力。\n");
        if( (int)me->query("neili")< 300)
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup")
        || (int)me->query_temp("shift"))
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_temp("jingang") ) 
                return notify_fail("你的全部功力都运在大金刚拳上了。\n");
        if( (int)me->query_temp("zuida") ) 
                return notify_fail("你内息翻滚在八仙醉打中，一时提不起易筋经神功。\n");

        skill = me->query_skill("force");

        message_vision(HIR "$N舌尖一咬，喷出一口鲜血，运起易筋经神功已将全身潜力尽数提起！\n" NOR, me);

        me->add_temp("apply/attack", skill);
        me->add_temp("apply/dodge", skill);
        me->set_temp("powerup", 1);
        me->add("neili", -300);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me,HIC"你的易筋经神功运行完毕，将内力收回丹田。\n"NOR);
}
int clean_up()
{
        return 1;
}
void reset()
{
}
