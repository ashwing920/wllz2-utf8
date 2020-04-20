// diezhang.c (昆仑掌法)

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int damage;
	damage = ((int)me->query_skill("kunlun-zhang",1) + (int)me->query_skill("force")) * 3;
	damage += random(damage) + (int)me->query("jiali");

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("昆仑叠掌只能在战斗中对使用。\n");
	
	if(objectp(me->query_temp("weapon")))
		return notify_fail("你只能空手才可以使出昆仑叠掌。\n");
	
	if((int)me->query_skill("kunlun-zhang",1) < 150)
		return notify_fail("你的昆仑掌法不够娴熟，无法发挥昆仑叠掌的威力。\n");
	
	if((int)me->query_skill("xuantian-force",1) < 150)
		return notify_fail("你的玄天无极神功不够娴熟，无法发挥昆仑叠掌的威力。\n");
	
	if((string)me->query_skill_mapped("strike") != "kunlun-zhang"
	|| (string)me->query_skill_prepared("strike") != "kunlun-zhang")
		return notify_fail("你现在无法使用昆仑掌法，发挥昆仑叠掌的威力。\n");
	
	if((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力修为不够，无法发挥昆仑叠掌的威力。\n");
	
	if((int)me->query("jiali") < 1)
		return notify_fail("你的加力不足，昆仑叠掌恐怕将会绵绵无力。\n");
	
	if((int)me->query("neili") < 1500)
		return notify_fail("你的内力不足以发挥昆仑叠掌。\n");

	msg = HIG"$N深吸一口气，大喝一声，连续击出三掌，后招推着前招，掌力叠合在一起扑向$n！\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3){
		msg += HIW"$n眼前只见一个巨大的掌影，以泰山压顶之势，向自己袭来，正想抽身闪避，却已太迟。\n"NOR;
		msg += HIR"只听见“啪”的一声，$N的左掌已拍在了$n的天灵盖上，$n只觉眼前一黑，顿时头昏脑胀。\n"NOR;
		me->start_busy(5);
		target->receive_damage("qi",damage,me);
		me->add("neili",-500);
		call_out("combat_second",2,me,target,damage);
	}
	else {
		msg += HIW"谁知$n早有防备，身子一弯，避开了$N致命的一击。\n"NOR;
		me->add("neili",-500);
		me->start_busy(5);
	}
	message_vision(msg,me,target);
	return 1;
}
void combat_second(object me,object target,int damage)
{
	string msg;

	if(!me || !target || !living(me) || !living(target) 
	|| environment(me) != environment(target)
	|| !me->is_fighting(target) || !target->is_fighting(me)
	|| me->query("neili") < 500 || me->query_temp("weapon")) return;

	msg = HIW"$N身影一晃，立刻闪到$n身后，对着$n的后背又是一掌。\n"NOR;
	if(random(me->query_skill("dodge")) > (int)target->query_skill("dodge") / 4){
		msg += HIR"这掌确是阴毒，$n毫无防备，只听见“乓”的一声巨响，$N的右掌犹如重锤一般，击中了$n的后背。\n"NOR;
		me->start_busy(5);
		target->receive_wound("qi",damage/2,me);
		COMBAT_D->report_status(target);
		me->add("neili",-500);
		call_out("combat_next",2,me,target,damage);
	}
	else {
		msg += HIC"$n处变不惊，立刻向前迈开一步，身子轻轻一斜，使得$N打出了一个空招。\n"NOR;
		me->start_busy(5);
		me->add("neili",-500);
	}
	message_vision(msg,me,target);
	return;
}
void combat_next(object me,object target,int damage)
{
	string msg;

	if(!me || !target || !living(me) || !living(target) 
	|| environment(me) != environment(target)
	|| !me->is_fighting(target) || !target->is_fighting(me)
	|| me->query("neili") < 500 || me->query_temp("weapon")) return;

	msg = HIW"$N双手齐划，跟着双掌齐推，一招「北风卷地」，一股排山倒海的掌力，直扑$n面门。\n"NOR;
	if(random(me->query_skill("force")) > (int)target->query_skill("force") / 4){
		msg += HIR"$n闪躲不及，被$N的掌风袭中，落下一双深深的掌印。\n"NOR;
		me->start_busy(5);
		target->receive_damage("jing",damage/3,me);
		COMBAT_D->report_status(target);
		me->add("neili",-500);
	}
	else {
		msg += HIG"可是$n的内力修为早已超越$N之前，面对$N的掌风，仍然丝毫无损。\n"NOR;
		me->add("neili",-500);
		me->start_busy(6);
	}
	message_vision(msg,me,target);
	return;
}