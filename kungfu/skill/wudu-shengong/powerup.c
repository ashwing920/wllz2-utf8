// powerup.c

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me )
                return notify_fail("你只能用五毒神功提升自己的战斗力。\n");

        if( (int)me->query("neili") < 200)
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -200);
        me->receive_damage("qi",0);

        message_vision(HIM"$N潜运内力，体内真气灌顶，顿时脸色发紫，眼睛泛起阵阵杀气！\n"NOR,me);

        me->add_temp("apply/attack", skill/2);
        me->add_temp("apply/dodge", skill/2);
        me->set_temp("powerup", 1);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/2:),skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        if((int)me->query_temp("powerup")){
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的五毒神功运行完毕，缓缓将内力收回丹田。\n");
        }
}

int clean_up()
{
        return 1;
}
void reset()
{
}
