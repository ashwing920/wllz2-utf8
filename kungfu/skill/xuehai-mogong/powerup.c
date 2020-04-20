// powerup.c 血海魔功加力

#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;

        if(target != me)
                return notify_fail("你只能提升自己的战斗力。\n");
        if((int)me->query("neili")< me->query("max_neili")/ 20 )
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("force");
        message_vision(HIR"$N施展血海魔功，暴喝一声，将内力尽数提起！\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("powerup", 1);
        me->add("neili",-me->query("max_neili")/ 20);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        if((int)me->query_temp("powerup") ){
                me->add_temp("apply/attack", - amount);
                me->add_temp("apply/dodge", - amount);
                me->delete_temp("powerup");
                tell_object(me, "你的血海魔功运行完毕，将内力收回丹田。\n");
        }
}

int clean_up()
{
        return 1;
}
void reset()
{
}
