// 绝天四式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int j;
	j = me->query_skill("miexian-zhang")/2;

	if( !target ) target = offensive_target(me);
	if( !target || !me->is_fighting(target) || !living(target))
		return notify_fail("「绝天四式」只能在战斗中对对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「绝天四式」！\n");

	if( (int)me->query_skill("miexian-zhang", 1) < 150 )
		return notify_fail("你的灭仙掌还不够娴熟，使不出「绝天四式」绝技。\n");
	if( (int)me->query_skill("xuehai-mogong", 1) < 150 )
		return notify_fail("你的血海魔功等级还不够，使不出「绝天四式」绝技。\n");
	if (me->query_skill_mapped("force") != "xuehai-mogong")
		return notify_fail("你所使用的内功不对。\n");
	if( (int)me->query_skill("force",1) < 200 )
		return notify_fail("你的内功等级不够，不能使用「绝天四式」。\n");

	if( (int)me->query_str() < 35 )
		return notify_fail("你的膂力还不够强劲，使不出「绝天四式」来。\n");

	if( (int)me->query("max_neili") < 1200)
		return notify_fail("你现在内力太弱，使不出「绝天四式」。\n");      

	if( (int)me->query("neili") < 400 )
		return notify_fail("你现在真气太弱，使不出「绝天四式」。\n");


	message_vision(WHT"\n$N一声断喝，双掌齐出，挟起满天飞沙！使的正是灭神掌中的精髓「绝天四式」！\n"NOR,me);

	target->set_temp("block_msg/all",1);
	me->add_temp("str", j);
	me->add_temp("apply/strike", j);
	me->add_temp("apply/damage", j);
	me->add_temp("apply/attack", j/2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("str", -j);
	me->add_temp("apply/strike", -j);
	me->add_temp("apply/damage", -j);
	me->add_temp("apply/attack", -j/2);
	me->add("neili", -400);
	target->delete_temp("block_msg/all");
	me->start_busy(3);
	target->start_busy(1+random(2));
	return 1;
}
