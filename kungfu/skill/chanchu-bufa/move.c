// move.c 金蝉脱壳

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill;
	skill = (int)me->query_skill("chanchu-bufa",1);

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("你只能在战斗中运用「金蝉脱壳」逃离敌人的战圈。\n");
	
	if((int)me->query_skill("hamagong",1) < 120)
		return notify_fail("你的蛤蟆功修为不够，无法运用「金蝉脱壳」。\n");
	
	if((int)me->query_skill("chanchu-bufa",1) < 120)
		return notify_fail("你的蝉蜍步法不够熟练，无法运用「金蝉脱壳」。\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你现在内力不足，无法运用「金蝉脱壳」。\n");

	msg = HIC"\n只见$N身法陡然加快，运用蟾蜍步法当中的绝技「金蝉脱壳」，企图逃脱$n的战圈。\n"NOR;

	if(random((int)me->query_skill("dodge",1)) > (int)target->query_skill("dodge",1) / 3) {
		msg += HIW"\n成功了！只见$N身影一晃，避开$n的攻击，顿时跳开数丈之远。\n"NOR;
		me->remove_all_enemy(1);
		target->remove_all_enemy(1);
		target->start_busy(1);
		me->add("neili",-200);
	} else {
		msg += HIR"\n糟糕！被揭穿了！！$n看穿了$N的诡计，身影一晃，挡在了$N的跟前！\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}
