
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;

	if(!me->is_fighting())
		return notify_fail("唱仙法只能在战斗中使用。\n");

	if(!target ) target = offensive_target(me);
	if(!target||  !target->is_character()||  !me->is_fighting(target) )
		return notify_fail("唱仙法只能在战斗中使用。\n");

	if((int)me->query_skill("shenlong-xinfa",1) < 150 )
		return notify_fail("你的神龙心法还不够娴熟，无法使用唱仙法。\n");

	if((int)me->query_skill("shedao-qigong", 1) < 150 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法。\n");

	if( me->query("family/family_name") != "神龙教")
		return notify_fail("你不是神龙教弟子，如何能用唱仙大法？\n");

	if((int)me->query_temp("apply/attack")<=0
	||(int)me->query_temp("apply/dodge") <=0
	||(int)me->query_temp("apply/defense") <=0 )
		return notify_fail("你目前战斗力太低,不能再恢复内力了。\n");

	if((int)me->query_temp("chang") >= 50 )
		return notify_fail("你已经唱得太久了,不能再唱了。\n");

	if((int)me->query("neili") > (int)me->query("max_neili") * 3)
		return notify_fail("你的内力已经超越了你能承受的范围。\n");

	skill = (int)me->query_skill("force",1);

	message_vision(HIR "只听$N口中念念有词，顷刻之间内力大涨！\n" NOR, me);
	me->add_temp("apply/attack",-skill/100);
	me->add_temp("apply/dodge",-skill/100);
	me->add_temp("apply/defense",-skill/100);
	me->add_temp("chang",-1);
	me->add("neili",500);
	return 1;
}
