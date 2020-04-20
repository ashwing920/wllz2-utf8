// suogu.c 锁骨手

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, damage;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「锁骨手」只能对战斗中的对手使用。\n");

	if(!me->is_fighting())
		return notify_fail("「锁骨手」只能对战斗中的对手使用。\n");

	if(objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须放下"+ weapon->name()+"才可以使用锁骨手！\n");

	if( me->query_str() < 40 )
		return notify_fail("你的膂力太弱, 无法发挥「锁骨手」的威力！\n");

	if((int)me->query_skill("shenghuo-shengong",1) < 150 &&
	(int)me->query_skill("jiuyang-shengong",1) < 150 &&
	(int)me->query_skill("hunyuan-yiqi",1) < 150)
		return notify_fail("你的内功心法不够，不能使用锁骨手！\n");

	if((int)me->query("jiali") < 10)
		return notify_fail("你的加力太弱，无法发挥锁骨手的威力。\n");

	skill = (int)me->query_skill("sougu",1);

	if( skill < 150)
		return notify_fail("你的搜骨鹰爪功等级不够, 不能使用「锁骨手」！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够，无法运用「锁骨手」！\n");

	me->clean_up_enemy();
	msg = HIR"只见$N手法陡然增快，顺着$n的招式，迅速的向$n的肩膀抓去。\n"NOR;

	damage = skill + (int)me->query_skill("claw") + (int)me->query("jiali") * 2;
	ap = me->query_skill("claw")/3 + skill + me->query_str();
	dp = target->query_skill("dodge")/2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > random(dp) ){
		me->add("neili",- 200);
		msg += HIR"只听见“啪”的一声，$n闪躲不及，左臂已经被$N抓破，落下五道深深的爪印。\n"NOR;
		me->start_busy(2);
		target->receive_wound("qi",damage,me);
		target->receive_damage("qi",damage / 2,me);
		target->start_busy(random(2)+1);
	}
	else{
		msg += HIY"$n早已看穿了$N的攻势，右手一挡，将$N的手臂弹开。\n"NOR;
		me->add("neili",- 100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	COMBAT_D->report_status(target);
	return 1;
}
