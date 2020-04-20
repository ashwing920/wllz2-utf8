// xue.c  「血海狂龙」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("血海狂龙只能对战斗中的对手使用。\n");

	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("只有空手才可以使用「血海狂龙」。\n");

	if( (int)me->query_skill("miexian-zhang", 1) < 200 )
		return notify_fail("你的灭仙掌不够娴熟，不会使用「血海狂龙」。\n");

	if( (int)me->query_skill("xuehai-mogong", 1) < 150 )
		return notify_fail("你的血海魔功不够高，不会使用血海狂龙。\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你的内力不够发挥血海狂龙！\n");

	msg = HIR"$N内息倒逆，将内力运于手掌之间，一式「血海狂龙」随着真气一并击出，瞬间一片掌影逼向$n。\n"NOR;
	if (random(me->query_skill("force")) > target->query_skill("force")/3 ){
		me->start_busy(3);
		target->start_busy(random(3));
		damage = (int)me->query_skill("xuehai-mogong", 1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -damage/5);
		if ( damage < 40 ) msg += HIY"结果$N受到$n的内力反震，虽然击中$N，自己却闷哼一声向后退了两步。\n"NOR;
		else if( damage < 80 ) msg += RED"结果$N被$n以内力反震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
		else msg += HIR"$n茫然不知所措，结果被$N一掌击中前胸，$n眼前一黑，被击飞出两丈许！！！\n"NOR;
	} else
	{
		me->start_busy(2);
		msg += HIG"可是$p看破了$P的企图，早就闪在了一边。\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}
