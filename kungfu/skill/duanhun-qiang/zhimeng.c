// zhimeng.c 执梦为真

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg,dodge_skill,name;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("执梦为真只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "spear" )
		return notify_fail("你手中无枪，无法使用「执梦为真」！\n");

	if((int)me->query_skill("duanhun-qiang",1) < 400 )
		return notify_fail("你的断魂枪法不够娴熟，不能使用「执梦为真」。\n");

	if((int)me->query_skill("force",1) < 400)
		return notify_fail("你的内功修为不够，不能使用「执梦为真」。\n");

	if((int)me->query("neili") < 3000)
		return notify_fail("你现在内力太弱，不能使用「执梦为真」。\n");

	if((int)me->query("jingli") < 500)
		return notify_fail("你的灵力不够，不能使用「执梦为真」。\n");

	me->clean_up_enemy();
	name = weapon->query("name");
	msg = HIW"只见$N抽身一转，一式「执梦为真」，反手之间将手中的"+ name + HIW"向$n直刺而去！\n"NOR;
	if(random(me->query("combat_exp")) > target->query("combat_exp") / 3)
	{
		msg += HIR"\n只听见“扑哧”一声，"+ name +HIR"在$n的胸口对穿而出，顷刻间鲜血从创口喷射而出！！\n"NOR;
		me->start_busy(3);
		damage = (int)me->query_skill("spear",1) + (int)me->query_skill("force",1);
		damage += (int)me->query_skill("duanhun-qiang",1) + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing",damage/2,me);
		me->add("neili",-1000);
		me->add("jingli",-500);
	}
	else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += HIY + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}
