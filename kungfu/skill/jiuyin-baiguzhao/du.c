//du.c 九阴白骨爪施毒

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character()|| !me->is_fighting(target) )
		return notify_fail("施毒只能对战斗中的对手使用。\n");

	if(environment(me)->query("no_fight") )
		  return notify_fail("施毒只能在战斗中使用。\n");


	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才可以施毒。\n");

	if((int)me->query_skill("bibo-shengong", 1) < 120 )
		return notify_fail("你的碧波神功不够娴熟，不能施毒。\n");

	if((int)me->query_skill("jiuyin-baiguzhao", 1) < 120)
		return notify_fail("你的九阴白骨爪不够娴熟，不能施毒。\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够了。\n");

	msg = HIB "$N将毒质运于指上，双手手指微微泛出蓝光，抓向$n。";

	me->start_busy(1);
	me->add("neili",-200);

	if( random( (int)me->query_skill("jiuyin-baiguzhao",1)) > random(target->query_skill("dodge") ) ) {
		msg += HIB"结果$p被$N抓出一条长长的"+HIR"血痕！\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("jiuyin-baiguzhao",1)/10,me);
		target->receive_wound("qi",15 + random(10),me);
		target->apply_condition("jy_poison", random(me->query_skill("jiuyin-baiguzhao",1)/5) + 1 +
		target->query_condition("jy_poison"));
		target->start_busy(random(2));
	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(random(4));
	}
	message_vision(msg, me, target);
	return 1;
}
