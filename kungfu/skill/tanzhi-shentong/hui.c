// hui.c 挥斥方遒
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill,damage;

	skill = (int)me->query_skill("tanzhi-shentong",1);

	if(!me->is_fighting())
		return notify_fail("「挥斥方遒」只能在战斗中使用。\n");

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「挥斥方遒」只能在战斗中使用。\n");

	if ( objectp(weapon = me->query_temp("weapon")))
		return notify_fail("运用挥斥方遒时必须空手。\n");

	if( (int)me->query_skill("bibo-shengong",1) < 200)
		return notify_fail("你的碧波神功等级不够，不能使用「挥斥方遒」！\n");

	if( skill < 220)
		return notify_fail("你的弹指神通等级不够, 不能使用「挥斥方遒」！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力不够，无法运用「挥斥方遒」！\n");
 
	me->clean_up_enemy();

	msg = HIC "$N使出弹指神通之「挥斥方遒」，顿时眼内精光暴射，杀气逼人！\n";
	message_vision(msg, me, target);
	if( random(me->query("combat_exp")) > target->query("combat_exp") / 4)
	{
		me->add("neili",-400);
		msg = HIR"$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n" NOR;
		damage = (me->query_str() + skill) * 2;
		damage += random(damage);
		if((int)target->query("neili") > 1) target->add("neili", -damage);
		if((int)target->query("neili") < 0) target->set("neili",0);
		target->receive_wound("jing",damage,me);
		me->start_busy(3);
	}
	else
	{
		msg = HIG"可是$n的看破了$N的企图，立刻采取守势，使$P的「挥斥方遒」没有起到作用。\n"NOR;
		me->add("neili",-200);
		me->start_busy(5);
	}
	message_vision(msg, me, target);
	return 1;
}
