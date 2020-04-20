// powerup.c

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
	int skill;
	if( target != me )
		return notify_fail("你只能用临济庄功提升自己的战斗力。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");

	if((string)me->query("family/family_name") != "峨嵋派")
		return notify_fail("可能缺乏师长指点，你运起临济十二庄，可是武功却毫无丁点长进。\n");

	skill = me->query_skill("force");

	me->add("bellicosity", 100 + skill/2 );
	me->add("neili", -100);
	me->receive_damage("qi",0);

	message_vision(MAG"$N微一凝神，运起临济庄，一声娇喝！\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/3:),skill);
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
	tell_object(me, "你的临济庄运行完毕，将内力收回丹田。\n");
	}
}
int clean_up()
{
	return 1;
}
void reset()
{
}

