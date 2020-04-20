// 此去彼来perform�?

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string *limbs;
	int a,b,count, damage = 0;
	int arg = (int)(me->query_skill("liumai-shenjian", 1) / 30);

	if(!target) target = offensive_target(me);
	if( !target || !me->is_fighting(target) || !target->is_fighting(me))
		return notify_fail("「此去彼来」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「此去彼来」！\n");

	if((int)me->query_skill("liumai-shenjian", 1) < 300 )
		return notify_fail("你的六脉神剑不够娴熟，不会使用「此去彼来」。\n");

	if( (int)me->query_skill("force") < 200 )
		return notify_fail("你的内功等级不够，不能使用「此去彼来」。\n");

	if((int)me->query_skill("kurong-changong",1) < 200)
		return notify_fail("你的枯荣禅功不够娴熟，无法使用六脉神剑特殊攻击法！\n");

	if( (int)me->query_str() < 26 )
		return notify_fail("你的膂力不够强，不能使用「此去彼来」。\n");

	if( (int)me->query("neili", 1) < 150 * arg )
		return notify_fail("你现在的内力不够使用「此去彼来」进行攻击。\n");

	me->clean_up_enemy();

	a=(int)me->query("max_neili") +1;
	b=(int)target->query("max_neili") +1;

	message_vision(MAG"$N十指连动，忽伸忽缩，或点或按，空中气流激荡，剑气自$N指中汹涌而出，此去彼来，连绵无尽。\n" NOR, me, target);

	if( random(me->query("combat_exp")) > target->query("combat_exp") / 3 ){
		limbs = target->query("limbs");

	for(count = 0; count < arg; count++) {
		message_vision(replace_string(SKILL_D("liumai-shenjian")->query_action(me, me->query_temp("weapon"))["action"],"$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
		damage = damage+200+random(100);
	}
		damage = (1 + me->query("jiali")/300) * damage*a/b ;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
		me->add("neili", -150 * arg);
		me->start_busy(2);
		COMBAT_D->report_status(target);
	}
	else {
		me->start_busy(arg/2+1);
		me->add("neili", -200);
		target->add("neili", -100);
		message_vision(RED"\n$N就地一滚，躲开了攻击，吓的脸色惨白。\n"NOR,target);
	}

	return 1;
}
