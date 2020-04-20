// fen.c 焚心以火
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp,damage;

	skill = (int)me->query_skill("huoyan-dao",1);

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「焚心以火」只能对战斗中的对手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手运功。\n");

	if( skill < 120)
		return notify_fail("你的「火焰刀」等级不够, 不能使出「焚心以火」！\n");

	if((string)me->query_skill_mapped("strike") != "huoyan-dao")
		return notify_fail("你没有采用「火焰刀」为掌法，无法发挥「焚心以火」的威力！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够，无法运功！\n");

	if((int)me->query("jiali") < 1)
		return notify_fail("你没有设置加力，「焚心以火」将毫无威力！\n");
 
	msg = HIC "$N聚气于掌，使出一招「焚心以火」，向$n的胸口击去。\n"NOR;
	message_vision(msg, me, target);

	ap = (int)me->query("combat_exp") + skill * 400;
	dp = (int)target->query("combat_exp") / 2;

	if( dp < 1 ) dp = 1;
	if( random(ap) > dp ){
		me->add("neili",-200);
		msg = HIR"$n只觉得眼前一黑，“哇”的一声喷出一口鲜血！\n"NOR;
		damage = skill + (int)me->query("jiali");
		damage = damage + random(damage);
		target->receive_wound("qi",damage,me);
		if((int)target->query("neili") >= skill + (int)me->query_skill("force"))
		target->add("neili",- (skill + (int)me->query_skill("force")));
		me->start_busy(2);
	}
	else
	{
		msg = HIW"只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		me->add("neili",-200);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}
