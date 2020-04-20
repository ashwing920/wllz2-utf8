// powerup.c

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;

	if( target != me ) return notify_fail("你只能葵花心法来提升自己的战斗力。\n");

	if( (int)me->query("neili") < (int)me->query("max_neili") / 20)
		return notify_fail("你的内力不够！");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("kuihua-xinfa");

	me->add("neili", -(int)me->query("max_neili") / 20);
	me->receive_damage("qi", 0);

	message_vision(HIR"$N高喝一声：“嗨！！”一股真气全然升起，游满全身。\n"NOR,me);

	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	if(!me) return;
	if((int)me->query_temp("powerup") ) {
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的葵花心法运行完毕，将内力收回丹田。\n");
	}
}
int clean_up()
{
	return 1;
}
void reset()
{
}
