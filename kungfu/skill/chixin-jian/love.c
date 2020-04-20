// love.c 痴心情长剑-横刀夺爱

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("横刀夺爱只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	||(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if((int)me->query_skill("chixin-jian", 1) < 100 )
		return notify_fail("你的痴心情长剑法不够娴熟，不能使用横刀夺爱。\n");

	if((int)me->query_skill("beiming-shengong", 1) < 120 )
		return notify_fail("你的本门内功不够娴熟，不能使用横刀夺爱。\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你现在内力太弱，不能使用横刀夺爱。\n");

	me->clean_up_enemy();
	msg = HIC "$N清啸一声，响澈云霄，一式「横刀夺爱」横空出世。\n"NOR;
	
	me->add("neili", - 200);
	if (random((int)me->query_skill("force",1)) > (int)target->query_skill("force")/4 ){
		me->start_busy(3);
		damage = (int)me->query_skill("chixin-jian",1) + (int)me->query_skill("force");
		damage = damage + random(damage/2) + (int)me->query_temp("apply/damage");
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi",damage / 2,me);
		msg += HIR"\n$n看到$N雷霆一击，顿时鄂立当场，不知如何招架！被刺了个正着。\n\n"NOR;
	}
	else
	{
		me->start_busy(3);
		msg += HIW"\n可是$p看破了$P的企图，斜跃避开。\n\n"NOR;
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target);
	return 1;
}
