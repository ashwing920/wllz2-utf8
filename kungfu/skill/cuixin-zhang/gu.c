// /kungfu/skill/gu.c 孤注一掷

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg,dodge_skill;

	damage = (int)me->query_skill("bibo-shengong",1) + (int)me->query_skill("cuixin-zhang",1);
	damage = (random(damage) + damage) * 3;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「孤注一掷」只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「孤注一掷」！\n");

	if((int)me->query_skill("cuixin-zhang", 1) < 150 )
		return notify_fail("你的催心掌不够娴熟，运用「孤注一掷」为时过早！\n");

	if((int)me->query_skill("bibo-shengong", 1) < 150 )
		return notify_fail("你的碧波神功火候不够，无法发挥「孤注一掷」的威力！\n");

	if((string)me->query_skill_mapped("force") != "bibo-shengong")
		return notify_fail("你必须借助碧波神功的来发挥催心掌的威力。\n");

	if( (int)me->query("neili") < 300 || (int)me->query("neili") < damage / 10 )
		return notify_fail("你现在内力太弱，不能使用「孤注一掷」！\n");

	me->clean_up_enemy();
	msg = HIW"$N运起碧波神功，使出催心掌的精髓「孤注一掷」，双掌平推攻向$n。\n"NOR;
	if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3 ){
		target->start_busy(random(3)+1);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -damage/10);
		me->start_busy(2);
		if( damage < 40 )
			msg += HIY"结果$n被$N双掌打在胸口，闷哼一声。\n"NOR;
		else if( damage < 80 )
			msg += HIY"结果$n被$N以双掌打在胸口，「嘿」地一声退了两步。\n"NOR;
		else if( damage < 160 )
			msg += RED"结果$n被$N以双掌打在胸口，有如受到一记重锤，连退了五六步！\n"NOR;
		else
			msg += HIR"结果$n被$N的双掌打在胸口，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;

	}
	else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += HIC + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + NOR;
		me->start_busy(3);
		me->add("neili",-300);
	}
	message_vision(msg, me, target);
	return 1;
}
