// quick_attack.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg,dodge_skill;
	int damage,i;

	if( !target ) target = offensive_target(me);
	if( !target ||!target->is_character() ||!me->is_fighting(target))
		return notify_fail("移形换影只能对战斗中的对手使用。\n");

	if((int)me->query("neili") < 200 ) 
		return notify_fail("你的内力不够。\n");

	if((int)me->query_skill("taxue-steps",1) < 120)
		return notify_fail("你的踏雪无痕还不够娴熟，无法使用移形换影。\n");

	me->clean_up_enemy();
	msg = HIC"只见$N施展绝顶轻功，分身化做数个身影，飘然向$n缠绕而去！\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3){
		msg +=HIG"结果$p被$P缠得眼花缭乱，$P立刻趁势攻击！\n" NOR;
		damage = (int)me->query_skill("dodge") + (int)me->query_skill("force");
		damage += random(damage);
		target->start_busy(3);
		if(objectp(me->query_temp("weapon"))) target->receive_wound("qi",damage,me);
		else target->receive_damage("qi",damage / 2,me);
		me->add("neili",-200);
		me->start_busy(2);
	}
	else {
		dodge_skill = to_chinese((string)target->query_skill_mapped("dodge"));
		msg += HIW"只见$p运用"+ dodge_skill +"，识破了$P的诡计，飘然退开。\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target);
	return 1;
}
