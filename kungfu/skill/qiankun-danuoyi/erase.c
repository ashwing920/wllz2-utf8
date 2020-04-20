// erase.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( !me->is_fighting() )
                return notify_fail("乾坤大挪移神功化力之术只能在战斗中使用。\n");
        if( target != me ) 
                return notify_fail("你只能用乾坤大挪移神功化解对自己的攻击。\n");

        if( (int)me->query("neili") < 300 ) 
                return notify_fail("你的内力不够。\n");

        if( me->query_temp("shift")
        || me->query_temp("powerup")) 
                return notify_fail("你已经在运功中了。\n");

        skill = (int)me->query_skill("qiankun-danuoyi",1);

        me->add("neili", -300);
        me->receive_damage("qi", 0);

        write(HIC"你心念一转，运起乾坤大挪移神功，打算把敌人的攻击化得无影无踪。\n"NOR);

        me->add_temp("apply/parry",skill);
        me->set_temp("shift","erase");

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        if (me->query_temp("shift") == "erase" ){ 
                me->add_temp("apply/parry", - amount);
                me->delete_temp("shift");
                message_vision("$N的乾坤大挪移神功运行完毕，缓缓地将内力收回了丹田。\n", me);
        }
}
int clean_up()
{
        return 1;
}
void reset()
{
}
