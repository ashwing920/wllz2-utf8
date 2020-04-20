// chan.c 日月鞭法「缠绕」诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if((int)me->query_skill("riyue-bian",1) < 80)
		return notify_fail("你的「日月鞭法」还没学到家，用不了「缠」字诀。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你的内力不够发挥缠字诀。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "whip")
		return notify_fail("你手中无鞭，无何使用「缠」字诀？\n");

	if(target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

	me->clean_up_enemy();
	msg = CYN "$N使出日月鞭法「缠绕」诀，连挥数鞭企图把$n的全身缠绕起来。\n";
	me->add("neili",-300);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4) {
		msg += "结果$p被$P攻了个措手不及。\n" NOR;
		target->start_busy((int)me->query_skill("riyue-bian",1) / 40 );

	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
