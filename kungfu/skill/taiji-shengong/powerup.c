// powerup.c 太极神功加力

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;
	if( target != me )
		return notify_fail("你只能用太极神功来提升自己的战斗力。\n");
	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("taiji-jiali") )
		return notify_fail("你已经在运功中了。\n");

	skill = (int)me->query_skill("force");
	me->add("neili", -200);
	me->receive_damage("qi", 0);
	message_vision(HIY"$N微一凝神，运起太极神功，全身灌满真气，衣裳无风自舞，气势迫人。\n" NOR,me);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/armor", skill/3);
	me->set_temp("taiji-jiali", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect",me, skill/3:), skill);
	if(me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	if(!me) return;
	if((int)me->query_temp("taiji-jiali")){
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/armor", - amount);
		me->delete_temp("taiji-jiali");
		tell_object(me, HIC"你的太极神功运行完毕，将内力收回丹田。\n"NOR);
	}
}

int clean_up()
{
	return 1;
}
void reset()
{
}
