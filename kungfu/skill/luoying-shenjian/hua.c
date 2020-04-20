// /kungfu/skill/hua.c 落英剑法 势合形离

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;

	if( !target ) target = offensive_target(me);
	if( !target ||  !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「势合形离」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("luoying-shenjian", 1) < 150 )
		return notify_fail("你的落英剑法极不够娴熟，不会使用「漫天花雨」。\n");

	if( (int)me->query_skill("bibo-shengong", 1) < 150 )
		return notify_fail("你的碧波神功不够娴熟，不会使用「漫天花雨」。\n");

	attack_time = (int)me->query_skill("luoying-shenjian", 1) / 40;
		if(attack_time < 1) attack_time = 1;
		if(attack_time > 12) attack_time = 12;

	if((int)me->query("neili") < 400)
		return notify_fail("你的内力不够了。\n");

	if((int)me->query("neili") < attack_time * 100 )
		return notify_fail("你的内力不够发挥漫天花雨。\n");

	me->clean_up_enemy();
	msg = HIW "$N手腕一抖，一式「势合形离」，泛出数朵剑花连续递出。\n"NOR;
	message_vision(msg, me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/ 4 ){
	msg = HIG "结果$p被$P攻了个措手不及！\n" NOR;
	message_vision(msg, me, target);
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),SKILL_USAGE_ATTACK);
		me->set_temp("action_flag",0);
	}else break;
		me->add("neili", -400);
		me->start_busy(3);
	}
	else
	{
		msg = HIC"可是$p看破了$P的企图，并没有上当。\n" NOR;
		message_vision(msg, me, target);
		me->add("neili",-200);
		me->start_busy(4);
	}
	return 1;
}
