// ju.c 昊天掌-三花聚顶

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("三花聚顶只能对战斗中的对手使用。\n");

	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才可以使用三花聚顶。\n");
	if( (int)me->query_skill("haotian-zhang", 1) < 120 )
		return notify_fail("你的昊天掌不够娴熟，不会使用三花聚顶。\n");

	if( (int)me->query_skill("xiantian-qigong", 1) < 120 )
		return notify_fail("你的先天功不够娴熟，不会使用三花聚顶。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你现在内力太弱，不能使用三花聚顶。\n");

	msg = HIC "$N大喝一声，合身向$n扑上，双掌同时击出，是一招「三花聚顶」。\n"NOR;

	if( !target->is_fighting(me) ) target->fight_ob(me);
	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(1);
		damage = (int)me->query_skill("haotian-zhang", 1) + (int)me->query_skill("force",1);
		damage = damage/2 + random(damage/2) ;
		target->receive_damage("qi", damage,me);
		target->start_busy(4);
		me->add("neili", - 200);
		msg += HIR"结果$n被$N的气势所摄，一惊之下，竟然忘了抵挡！\n"NOR;

	}
	else
	{
		me->start_busy(3);
		msg += CYN"可是$p识破了$P这一招，斜斜一跃避开。\n"NOR;
		me->add("neili",-200);
	}
	message_vision(msg, me, target);

	return 1;
}
