// shield.c 北冥神功护体神功

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能用北冥神功来提升自己的防御力。\n");

	if( (int)me->query("neili") < 100  )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("beiming-shengong",1) < 120 )
		return notify_fail("你的北冥神功修为不够。\n");

	if( (int)me->query_temp("shield") )
		return notify_fail("你已经在运功中了。\n");

	skill = (int)me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(HIW"$N双手平举过顶，运起北冥神功，顿时全身笼罩在劲气之中！\n"NOR,me);

	me->add_temp("apply/armor",skill);
	me->set_temp("shield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill:), skill);
	if( me->is_fighting() ) me->start_busy(2);
	return 1;
}

void remove_effect(object me, int amount)
{
	if(!me) return;
	if((int)me->query_temp("shield")){
	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");
	tell_object(me, "你的北冥神功运行完毕，将内力收回丹田。\n");
	}
}
int clean_up()
{
	return 1;
}
void reset()
{
}
