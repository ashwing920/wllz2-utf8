// duo.c 空手入白刃

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp;
	skill = me->query_skill("zhemei-shou",1);

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("空手入白刃只能对战斗中的对手使用。\n");

	if((int)me->query_temp("duo"))
		return notify_fail("你已经在夺敌人的兵刃了。\n");

	if(objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用空手入白刃。\n");

	if(!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有兵器，你使用空手入白刃也是枉然。\n");

	if( skill < 120)
		return notify_fail("你的天山折梅手等级不够, 不能空手入白刃！\n");

	if( me->query("neili") < 100)
		return notify_fail("你的内力不够，无法空手入白刃！\n");

	me->clean_up_enemy();
	
	msg = CYN "$N凝神闭息，打算施展空手入白刃的绝技。\n";
	message_vision(msg, me);

	dp = target->query_dex() * 3;
	if( dp < 1 ) dp = 1;
	if( random(skill) > dp ){
		msg = HIW"$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
		me->add("neili",-200);
		target->start_busy(2);
		weapon2->move(environment(me));
		target->reset_action();
		me->start_busy(2);
	}
	else{
		me->add("neili",-200);
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
		me->start_busy(random(3)+1);
	}
	message_vision(msg, me, target);
	return 1;
}
