// powerfade.c

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;

        if( target != me ) return notify_fail("你只能用玉女心法压制自己的杀气。\n");

        if( (int)me->query("neili") < 100 ) return notify_fail("你的内力不够。\n");
        if( me->query_temp("powerfade") ) return notify_fail("你已经在运功中了。\n");
        if( (int)me->query("bellicosity") <= 0 ) return notify_fail("你现在毫无杀气。\n");

        skill = me->query_skill("force");

        me->add("bellicosity", - 100 - skill/3 );
        me->add("neili", -100);
        me->receive_damage("jing", 50);

        message_vision(HIC "$N气沉丹田，深吸了一口气，运起玉女心法，开始收敛自己的杀气 ....\n" NOR, me);
        me->set_temp("powerfade", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill / 3 :), skill / 20);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
	if( !me) return;
        if(me->query_temp("apply/attack") <= 0) me->delete_temp("apply/attack");
        if(me->query_temp("apply/dodge") <= 0)  me->delete_temp("apply/dodge");
        if(me->query_temp("apply/damage") <= 0) me->delete_temp("apply/damage");
        me->delete_temp("powerfade");
        message_vision("$N的玉女心法运行完毕，缓缓地将内力收回了丹田。\n", me);
}
int clean_up()
{
        return 1;
}
void reset()
{
}
