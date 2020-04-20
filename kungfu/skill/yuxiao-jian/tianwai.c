// tianwai.c 天外清音

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg,dodge_skill;
	object weapon, target;
	int skill, ap, dp, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("yuxiao-jian",1);

	if(!me->is_fighting())
		return notify_fail("「天外清音」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( me->query_skill("bibo-shengong",1) < 120)
		return notify_fail("你的碧波神功等级不够, 不能使用「天外清音」！\n");

	if( skill < 90)
		return notify_fail("你的玉箫剑法等级不够, 不能使用「天外清音」！\n");

	if( me->query("neili") < 200)
		return notify_fail("你的内力不够，无法运用「天外清音」！\n");

	msg = HIG"$N一声清啸，剑发琴音，剑附内力，一式「天外清音」，"+weapon->name()+ HIG"闪动不止，剑影如夜幕般扑向$n。\n"NOR;
	message_vision(msg, me, target);

	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		me->add("neili",-200);
		msg = HIR"$n顿时觉得眼前金光乱闪动，双耳嗡嗡内鸣，不知哪里一阵刺痛如针扎一般！\n" NOR;
		qi_wound = (int)me->query_skill("bibo-shengong",1) + skill;
		qi_wound = qi_wound + random(qi_wound);
		target->receive_damage("qi",qi_wound,me);
		target->receive_wound("jing",qi_wound/2,me);
		me->start_busy(2);
	}
	else
	{
		me->add("neili",-100);
		dodge_skill = (string)target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = HIG + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}
