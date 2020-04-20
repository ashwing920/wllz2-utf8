// powerup.c for xixin-dafa

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("只能用吸星大法来提升自己的战斗力。\n");

        if( (int)me->query("neili") < (int)me->query("max_neili")/ 20) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -(int)me->query("max_neili")/ 20);
        me->receive_damage("qi", 0);
        me->add("bellicosity",100);
        message_vision(HIR"$N凝神一聚，运起吸星大法，全身骨节发出一阵爆豆般的声响，一股摄人的劲气顷刻并发。\n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你又将吸星大法功力收回丹田。\n");
}
