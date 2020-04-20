// fuxue.c 封穴手

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if(!target) target = offensive_target(me);
	if(!target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「封穴手」。\n");

	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须放下武器才可以使用封穴手！\n");

	if((int)me->query_skill("bibo-shengong",1) < 150)
		return notify_fail("你碧波神功的功力不够，无法使用封穴手！\n");

	if((int)me->query_skill("hand",1) < 150)
		return notify_fail("你的手法修为不够，无法使用封穴手！\n");

	if((int)me->query_skill("lanhua-shou",1) < 150)
		return notify_fail("你的兰花拂穴手修为不足，无法使用封穴手！\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够, 不能使用封穴手！\n");

	if(target->query_condition("no_exert"))
		return notify_fail(target->name() +"已被你封闭了气海穴。\n");

	msg = HIM"$N右手反手而出，突然三指收拢，双指如针，迅速的向$n的气海穴刺去。\n"NOR;

	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3 ){
		msg +=  HIW"$n不知有诈，抬手正想接招，却早已被$N点中了气海穴。\n" NOR;
		target->apply_condition("no_exert",(int)me->query_skill("lanhua-shou",1)/ 10);
		me->add("neili", -300);
		me->start_busy(2);
	}
	else
	{
		msg += HIY"可是$n始终经验老道，早已看出当中有诈，挥手弹开了$N的双指。\n" NOR;
		me->add("neili",-200);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}
