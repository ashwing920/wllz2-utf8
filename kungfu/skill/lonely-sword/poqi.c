// poqi.c 破气式

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("lonely-sword",1);

	if( !(me->is_fighting() ))
		return notify_fail("「破气式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( skill < 120)
		return notify_fail("你的独孤九剑等级不够, 不能使用「破气式」！\n");

	if( me->query("neili") < (int)me->query("max_neili") / 20)
		return notify_fail("你的内力不够，无法运用「破气式」！\n");

	msg = HIC "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直刺$n的丹田。\n";
	message_vision(msg, me, target);

	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
		me->add("neili",- (int)me->query("max_neili") / 20);
		msg = "$N运起「破气式」，长剑斜挑对方小腹，$n顿时觉得眼前一花，气海\n";
		msg += "穴上微微一痛，全身真气狂泄而出！\n" NOR;
		neili_wound = 300 + random(skill);
		if(neili_wound > target->query("neili"))
		neili_wound = target->query("neili");
		qi_wound = (int)me->query_skill("lonely-sword",1)+(int)me->query_skill("sword",1)/2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi"))
		qi_wound = 100;
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		me->start_busy(2);
	}
	else
	{
		if(userp(me))
		me->add("neili",-(int)me->query("max_neili") / 20);
		msg = "可是$n看破了$N的企图，立刻守紧门户，几经艰难终于还招挡开。\n"NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);

	return 1;
}
