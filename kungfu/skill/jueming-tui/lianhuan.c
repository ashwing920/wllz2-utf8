//lianhuan.c 连环 perform

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("连环诀只能对战斗中的对手使用。\n");

	if( target->is_busy())
		return notify_fail(target->name() + "目前正晕头转向，乘机进攻吧！\n");

	if( me->query_skill("shenlong-xinfa", 1) < 120 )
		return notify_fail("你的神龙心法火候未到，无法施展连环诀！\n");

	if( me->query_skill("leg",1) < 120)
		return notify_fail("连环腿需要精湛的基本腿法配合，方能有效施展！\n");

	if( me->query_skill("jueming-tui",1 ) < 120)
		return notify_fail("你绝命腿修为不足，还不会使用连环诀！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用连环诀！\n");

	if( (int)me->query("jingli") < 150 )
		return notify_fail("你的精神无法集中。\n");

	msg = HIY "\n 突然间$N身形腾空而起，凌空向$n奋力连踢几腿！\n" NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
		target->start_busy((int)me->query_skill("jueming-tui",1) / 80);
		damage = (int)me->query_skill("shenlong-xinfa",1) + (int)me->query_skill("jueming-tui",1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", - 300);
		me->start_busy(2);
		if( damage < 40 ) msg += HIY"结果$n被$N的连环腿踢得晕头转向！\n" NOR;
		else msg += HIR"结果$n被$N的连环腿踢中要害，「哇！」的一口鲜血喷涌而出！\n"NOR;
	}
	 else {
		msg += "可是$p看破了$P的企图，巧妙得躲了开去。\n" NOR;
		me->start_busy(2 + random(3));
	}
	message_vision(msg, me, target);
	return 1;
}
