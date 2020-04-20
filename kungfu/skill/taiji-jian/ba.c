// ba.c　四两拔千斤

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int forces;
	object weapon;

	if( !target) target = offensive_target(me);
	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「四两拨千斤」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_skill("taiji-jian",1) < 120)
		return notify_fail("你的太极剑法还不够纯熟！\n");

	forces = (int)me->query("jiali") /10 * (int)me->query_str();

	if((int)me->query("neili") < forces / 3)
		return notify_fail("你的内力不足！\n");

	if((int)me->query("jiali") < 1)
		return notify_fail("你没有设置加力，「四两拨千斤」将会毫无威力。\n");

	me->add_temp("apply/attack",forces);
	me->clean_up_enemy();
	message_vision(HIY "\n只见$N的动作突然慢下来，双手握着剑运起了太极剑的「四两拨千斤」，轻易的减消了$n的攻击！\n" NOR, me, target);
	target->receive_damage("qi",forces * 3,me);
	message_vision(HIY "\n$n还没反应过来，$N马上向$n刺去促势已久的第二剑！\n" NOR, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), SKILL_USAGE_ATTACK);
	message_vision(HIY  "\n第三剑！\n" NOR, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), SKILL_USAGE_ATTACK);
	me->start_busy(3);
	me->add("neili",-forces/3);
	me->add_temp("apply/attack",-forces);
	return 1;
}
