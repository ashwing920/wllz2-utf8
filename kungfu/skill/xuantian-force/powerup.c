// powerup.c

#include <ansi.h>

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
	if(target != me) 
		return notify_fail("你只能用玄天无极提升自己的战斗力。\n");
	if((int)me->query("neili") < (int)me->query("max_neili") / 20 ) 
		return notify_fail("你的内力不够。\n");
	if((int)me->query_temp("powerup") > 1) 
		return notify_fail("你已经不能再提升战力了。\n");

	skill = me->query_skill("xuantian-force",1);
	
	if (skill<80) return notify_fail("你的玄天无极还不够娴熟。\n");
	
	me->add("neili",-(int)me->query("max_neili") / 20);
	me->receive_damage("qi", 0);
	message_vision(HIR "$N长吸一口气，运起玄天无极已将全身潜力尽数提起！\n" NOR, me);
	me->add_temp("apply/attack", skill/4);
	me->add_temp("apply/dodge", skill/4);
	me->add_temp("powerup", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/4 :), skill/2);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}
void remove_effect(object me, int amount)
{
	if(!me) return;
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->add_temp("powerup",-1);
	tell_object(me, "你的玄天无极运行完毕，将内力收回丹田。\n");
}
int clean_up()
{
	return 1;
}
void reset()
{
}
