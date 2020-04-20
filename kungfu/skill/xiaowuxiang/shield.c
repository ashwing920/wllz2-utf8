// shield.c 小无相功护体神功

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;

        if( (int)me->query("neili") < 300)
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_skill("xiaowuxiang",1) < 40 )
                return notify_fail("你的小无相功修为不够。\n");

        if( (int)me->query_temp("huti"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -300);

        message_vision(HIW "$N双手平举过顶，运起小无相功，全身笼罩在劲气之中！\n" NOR, me);
        me->add_temp("apply/armor", skill);
        me->set_temp("huti", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/armor", - amount);
        me->delete_temp("huti");
        tell_object(me, "你的小无相功运行完毕，将内力收回丹田。\n");
}
int clean_up()
{
        return 1;
}
void reset()
{
}
