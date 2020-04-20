// huayu.c

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage,p;
	string msg,dodge_skill;
	object weapon;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("满天花雨只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		 || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("feixing-shu", 1) < 120)
		return notify_fail("你的飞星术不够娴熟，不会使用满天花雨。\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 120 )
		return notify_fail("你的化功大法不够娴熟，不能使用满天花雨。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你内力不够了。\n");

	damage = (int)me->query_skill("feixing-shu", 1) + (int)me->query_skill("huagong-dafa",1);
	damage = damage + random(damage);
	msg= HIC"\n只听一股劲风从$N的右侧发出，$N手中的"+weapon->name()+ HIC"如烟雨般向$n笼罩过去！\n\n"NOR;
	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 4){
		target->receive_wound("qi",damage,me);
		target->receive_wound("jing",damage / 2,me);
		target->start_busy(random(3));
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(me->query_skill("throwing"), "内伤");
		msg += "「$n"+eff_status_msg(p)+"」\n";
	} else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += HIY + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
	}
	me->add("neili", - 200);
	me->start_busy(2);
	message_vision(msg, me, target);
	return 1;
}
