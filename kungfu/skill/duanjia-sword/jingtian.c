// duanjia-sword.c  段家剑 惊天一击

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「惊天一击」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("duanjia-sword", 1) < 120 )
		return notify_fail("你的段家剑法不够娴熟，不会使用。\n");

	if( (int)me->query_skill("kurong-changong", 1) < 120 )
		return notify_fail("你的枯荣禅功修为不够高。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你现在内力太弱，不能使用「惊天一击」。\n");

	msg = CYN "$N一跃而起，手腕一抖，挽出一个美丽的剑花，飞向$n。\n"NOR;

	if(random((int)me->query_skill("force")) > (int)target->query_skill("force")/2 ){
		target->start_busy((int)me->query_skill("duanjia-sword") / 20 + 1);
		damage =  (int)me->query_skill("duanjia-sword", 1) + (int)me->query_skill("sword");
		target->receive_damage("qi", damage,me);
		me->add("neili", -damage);
		msg += HIR"只见$N人剑合一，穿向$n,$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
		me->start_busy(2);
	} else 	{
		msg += CYN"可是$p猛地向边上一跃,跳出了$P的攻击范围。\n"NOR;
		me->add("neili", - 200);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}
