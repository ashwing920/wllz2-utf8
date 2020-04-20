// panlong 盘龙诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill;
	object weapon;

	skill = (int)me->query_skill("tulong-daofa",1);

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("盘龙诀只能在战斗中使用。\n");

	if(skill < 150)
		return notify_fail("你的屠龙刀法还不够娴熟，无法使用盘龙诀。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type")!= "blade")
		return notify_fail("你现在手中无刀，无法使用盘龙诀牵制对手。\n");

	if((int)me->query_skill("jiuyang-shengong",1) < 150
	&& (int)me->query_skill("shenghuo-shengong",1) < 150 )
		return notify_fail( "你的内功修为不够，无法使用盘龙诀牵制对手。\n" );

	if((int)me->query("neili") < 200)
		return notify_fail("你现在内力不足。\n" );

	if( target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIC"只见$N招式突然变得十分怪异，手中"+ weapon->name()+ HIC"犹如蛟龙一般，向$n飘了过去。\n"NOR;
	if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3){
		msg += HIW"$n早知来势不妙，正想闪身避开，双腿却已被"+ weapon->name()+ HIW"紧紧盘住，动弹不得。\n"NOR;
		target->start_busy(skill / 50);
		me->start_busy(1);
		me->add("neili",-200);
	}
	else {
		msg += HIG"谁知$n早有防备，纵身飞起，跳开数丈之外。\n"NOR;
		me->add("neili",-200);
		me->start_busy(2);

	}
	message_vision(msg,me,target);
	return 1;
}
