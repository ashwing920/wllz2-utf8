// yi.c 一指乾坤

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int lvl;

	if( !target ) target = offensive_target(me);
	if( !target ||  !target->is_character() || !me->is_fighting(target))
		return notify_fail("「一指乾坤」只能对战斗中的对手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你不能使用武器！\n");

	if(!living(target) || target->is_busy())
		return notify_fail(target->name()+"现在正招架不及时，快放胆攻击吧！\n");

	lvl = (int)me->query_skill("canhe-zhi",1);

	if((int)me->query_skill("shenyuan-gong",1) < 120)
		return notify_fail("你的神元功修为不够，不能使用「一指乾坤」。\n");
		
	if( lvl < 120 )
		return notify_fail("你的参合指太生疏，不会使用「一指乾坤」。\n");

	if((int)me->query("neili") < 400)
		return notify_fail("你的内力不够，现在无法使用「一指乾坤」字决。\n");

	me->add("neili", -400);
	msg = HIG"$N趁$n不备，潜用内力于指尖，瞬间向$n的天罡穴指去。\n";

	if( random((int)me->query("neili") + (int)me->query_skill("canhe-zhi",1) * 10 ) 
	> random((int)target->query("neili") + (int)target->query_skill("dodge",1) * 10)) {
		msg += HIR"结果$p一声闷哼，被点了个正着，动弹不得。\n" NOR;
		target->receive_damage("jing",random(lvl) + lvl,me);
		target->start_busy(lvl/40);
	} else {
		msg += "可是$n早已发现了$N的诡计，轻身闪开了。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}
