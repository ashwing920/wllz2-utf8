// san.c  天女散花

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「天女散花」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("tianyu-qijian", 1) < 120 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");

	if( (int)me->query_skill("bahuang-gong", 1) < 120 )
		return notify_fail("你的八荒六合唯我独尊功不够高。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你现在内力太弱，不能使用「天女散花」。\n");

	msg = HIM"$N凝神息气，手腕疾抖，挽出千万个剑花，犹如「天女散花」般铺天盖地的飞向$n。\n"NOR;
	if(random(me->query_skill("force")) > target->query_skill("force") / 4 ){
		target->start_busy((int)me->query_skill("tianyu-qijian") / 60 + 1);
		damage = (int)me->query_skill("bahuang-gong", 1);
		damage = damage +  (int)me->query_skill("tianyu-qijian");
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", - 200);
		msg += HIR"只见$N剑花聚为一线，穿向$n，$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
		me->start_busy(2);
	} else
	{
		msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}
