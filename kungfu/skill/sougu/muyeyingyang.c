// muyeyingyang.c 牧野鹰扬

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

	if(me->query_temp("weapon"))
		return notify_fail("你必须空手才能使用牧野鹰扬！\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 120
	&& (int)me->query_skill("shenghuo-shengong",1) < 120)
		return notify_fail("你的内功心法修为不够，不能使用牧野鹰扬！\n");

	if((int)me->query_skill("sougu",1) < 120)
		return notify_fail("你的搜骨鹰爪功修为不够,目前还不能使用牧野鹰扬！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你内力现在不够, 不能使用牧野鹰扬！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = HIY "$N使出搜骨鹰爪功绝技「牧野鹰扬」，双爪蓦地抓向$n的全身要穴。\n";

	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "结果$p被$P攻了个措手不及，立时动弹不得！\n" NOR;
		target->start_busy( (int)me->query_skill("sougu",1) / 60 + random(2));
		me->add("neili", -200);
	} else {
		msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(5);
		me->add("neili", -200);
	}
	message_vision(msg, me, target);
	return 1;
}
