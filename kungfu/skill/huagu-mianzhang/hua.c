// hua.c 化骨绵掌

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill = (int)me->query_skill("huagu-mianzhang", 1);

	if( !target ) target = offensive_target(me);
	if(!target ||  !target->is_character() || !me->is_fighting(target) )
		return notify_fail("辣手化骨只能对对手使用。\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才可以使用辣手化骨。\n");

	if( environment(me)->query("no_fight"))
		return notify_fail("这里不能攻击别人！\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 120 )
		return notify_fail("你的神龙心法不够娴熟，不能化骨。\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 120 )
		return notify_fail("你的化骨绵掌不够娴熟，不能化骨。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够，不能化骨。\n");

	if(target->query_temp("huagu"))
		return notify_fail(target->name() +"已经全身瘫软，快全力攻击吧！\n");

	me->add("neili", - 200);

	msg = MAG "$N掌出如风轻轻落在$n肩头上。"NOR;

	if( random( (int)me->query_skill("huagu-mianzhang",1))> random(target->query_skill("dodge",1))/2 ){
		msg += MAG "结果只听扑的一声，$p被$P一掌拍中！\n" NOR;
		msg += MAG "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。\n" NOR;
		target->add_temp("apply/attack", -skill);
		target->add_temp("apply/dodge", -skill);
		target->add_temp("apply/defense", -skill);
		call_out("remove_effect",skill/3,skill,target);
		target->set_temp("huagu",1);
		me->start_busy(1);
	} else {
		msg += CYN"\n可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
void remove_effect(int amount,object target)
{
	if(!target) return;
	target->add_temp("apply/attack",amount);
	target->add_temp("apply/dodge",amount);
	target->add_temp("apply/defense",amount);
	target->delete_temp("huagu");
	tell_object(target,HIC"你只觉得瘫软的身躯已经逐渐恢复了原有的劲道。\n"NOR);
}
int clean_up()
{
	return 1;
}
void reset()
{
}
