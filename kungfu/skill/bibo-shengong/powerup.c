// powerup.c

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;

	if( target != me ) return notify_fail("你只能用碧波神功提升自己的战斗力。\n");

	if( (int)me->query("neili") < (int)me->query("max_neili") / 20)
		return notify_fail("你的内力不够！");
	if( (int)me->query_temp("powerup") ) return notify_fail("你已经在运功中了。\n");

	skill = (int)me->query_skill("force");

	me->add("neili",-(int)me->query("max_neili") / 20);
	me->receive_damage("qi", 0);

	message_vision(HIR"$N舌尖一咬，喷出一口鲜血，运起碧波神功已将全身潜力尽数提起！\n"NOR,me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("bellicosity",100);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if(!me) return;
	if((int)me->query_temp("powerup") ) {
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的碧波神功运行完毕，将内力收回丹田。\n");
	}
}
int clean_up()
{
	return 1;
}
void reset()
{
}
