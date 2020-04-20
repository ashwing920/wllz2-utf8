// xuhuan.c 金蟾归月

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill;
	skill = me->query_skill("chanchu-bufa",1);

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("金蟾归月只能在战斗中使用。\n");
	
	if((int)me->query_skill("hamagong",1) < 180)
		return notify_fail( "你的蛤蟆功修为不够。\n" );
	
	if((int)me->query_skill("chanchu-bufa",1) < 180)
		return notify_fail( "你的蟾蜍步法不够熟练。\n" );

	if((int)me->query("neili") < 500)
		return notify_fail( "你现在内力不足。\n" );

	if((string)me->query_skill_mapped("force") != "hamagong")
		return notify_fail("你必须配合蛤蟆功才可以发挥蟾蜍步的精髓金蟾归月！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIG
"$N脸色骤变，全身上下突然泛起一到绿氤之气，使出的正是「蟾蜍步」中至精
妙的一式「金蟾归月」。刹那间，$N的脚步陡然变得飞快，随着灵活百变的
脚步，又化出道道暗绿的身影，在$n跟前左右晃动，十分诡异！\n"NOR;

	if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/ 3 ) {
		msg += HIW"$n闪躲不及，被$N缠绕得头昏眼花，陷入一片混乱之中。\n"NOR;
		target->start_busy(skill / 50);
		target->apply_condition("chanchu_poison",skill / 5 + target->query_condition("chanchu_poison"));
		me->add("neili", -500);
		me->start_busy(1);
	} else {
		msg += HIW"显然$n早已看穿$N虚幻的招式，并没有中计。\n" NOR;
		me->add("neili", -100);
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	return 1;
}
