// reserve.c 蛤蟆功经脉倒转

#include <ansi.h>

void remove_effect(object me, int a_amount, int d_amount);
int exert(object me, object target)
{
        int skill;
        string msg;

        if((int)me->query_skill("hamagong", 1) < 120)
                return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");

        if((int)me->query("neili") < (int)me->query("max_neili") / 20) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("hmg_dzjm")) 
                return notify_fail("你已经倒转经脉了。\n");

        skill = me->query_skill("hamagong",1);
        msg = HIB "$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，防御力大增。\n"NOR;
        message_vision(msg, me, target);

        me->add_temp("apply/attack", -skill/3);
        me->add_temp("apply/dodge", skill/2);
        me->set_temp("hmg_dzjm", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/2 :), skill);

        me->add("neili", -(int)me->query("max_neili") / 20);
        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
        if(!me) return;
        if((int)me->query_temp("hmg_dzjm")) {
        me->add_temp("apply/attack", a_amount);
        me->add_temp("apply/dodge", - d_amount);
        me->delete_temp("hmg_dzjm");
        tell_object(me, HIY "你双手一撑，一跃而起，将内力收回丹田。\n");
        }
}
int clean_up()
{
        return 1;
}
void reset()
{
}
