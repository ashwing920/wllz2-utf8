// 怒海狂潮

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, j;
	i = me->query_skill("xuantie-sword", 1)/2;
	j = me->query_skill("sword")/2;

	if( !target ) target = offensive_target(me);
	if( !target ||  !target->is_character() ||  !me->is_fighting(target))
		return notify_fail("「怒海狂潮」只能在战斗中对对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "sword")
		return notify_fail("你手中无剑，无法使用「怒海狂潮」！\n");

	if((int)me->query_skill("xuantie-sword", 1) < 200 )
		return notify_fail("你的玄铁剑法还不够娴熟，使不出「怒海狂潮」绝技。\n");

	if((int)me->query_skill("force",1) < 200 )
		return notify_fail("你的内功等级不够，不能使用「怒海狂潮」。\n");

	if((int)me->query_str() < 35 )
		return notify_fail("你的膂力还不够强劲，无法使用「怒海狂潮」。\n");

	if(me->query_skill_mapped("sword") != "xuantie-sword"
	|| me->query_skill_mapped("parry") != "xuantie-sword")
	       return notify_fail("你现在无法使用「怒海狂潮」！\n");

	if((int)me->query("max_neili") < 1500 )
		return notify_fail("你现在内力修为不够，无法使用「怒海狂潮」。\n");

	if((int)me->query("neili") < 600 )
		return notify_fail("你现在真气太弱，无法使用「怒海狂潮」。\n");

	if((int)me->query("jingli") < 300)
		return notify_fail("你的精力不足，无法使用「怒海狂潮」。\n");

	me->clean_up_enmey();
	message_vision(HIW"\n$N默运内力，将内力尽传于手中的"+ weapon->query("name")+ HIW"中，只听见"+ weapon->query("name")+ HIW"发出阵阵撕裂般的巨响；\n从轻而响，从响而轻，忽寂然无声，忽轰轰震耳，反复七次，陡然间向$n席卷而去。\n"NOR,me,target);
	me->add_temp("apply/strength", i);
	me->add_temp("apply/damage",(i+j));
	me->add_temp("apply/attack", j);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("apply/strength", -i);
	me->add_temp("apply/damage",-(i+j));
	me->add_temp("apply/attack", -j);
	me->add("neili", -600);
	me->add("jingli",-300);
	me->start_busy(3);
	return 1;
}

