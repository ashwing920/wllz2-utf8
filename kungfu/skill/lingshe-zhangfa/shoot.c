// throw.c 灵蛇杖法喷毒

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon,snake;
	string msg;
	int damage;

	if( !target ) target = offensive_target(me);
	if(!target ||!target->is_character() ||!me->is_fighting(target) )
		return notify_fail("你只能在战斗中对别人喷毒。\n");

	if( (int)me->query_skill("hamagong", 1) < 120 )
		return notify_fail("你的蛤蟆功不够娴熟，不能喷毒。\n");

	if( (int)me->query_skill("lingshe-zhangfa", 1) < 120 )
		return notify_fail("你的灵蛇杖法不够娴熟，不能喷毒。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力不够，不能喷毒。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if(!weapon->query("race"))
		return notify_fail("你手中的"+ weapon->name() +"并没有附蛇，不能进行喷毒。\n");

	snake = find_object(weapon->query("race"));
	if(!snake) snake = load_object(weapon->query("race"));

	me->clean_enemy();

	msg = HIM"$N喉间发出刺耳的格格声响，"+ weapon->name() +HIM"前头的"+ snake->name() +HIM"猛地扬头，一阵粉红毒雾带着甜香喷向$n。\n";

	damage = (int)me->query_skill("lingshe-zhangfa",1);
	damage += damage*2 + random(damage);

	if((int)me->query_skill("lingshe-zhangfa",1) > random((int)target->query_skill("dodge"))){
		msg += HIM "结果$p被$P杖头小蛇一口喷中！" NOR;
		if((int)target->query("neili") < (int)me->query("neili")){
			msg += HIM"$n只闻到一阵甜香，眼前就模糊起来。\n" NOR;
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi",damage/2,me);
			target->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
			target->query_condition("snake_poison"));
		}
		else
		{
			msg += HIC"\n$n急运内力，一口真气向蛇毒喷去，顿时蛇毒反向$P飘了回去。\n" NOR;
			msg += HIM"$N只闻到一阵甜香，眼前就模糊起来。\n"NOR;
			me->receive_damage("qi",damage,target);
			me->apply_condition("snake_poison", random(me->query_skill("lingshe-zhangfa",1)/10) + 1 +
			me->query_condition("snake_poison"));
		}
		me->start_busy(2);
		me->add("neili",- 200);

	} else {
		msg += HIC"可是$n急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
		me->add("neili",- 100);
	}
	message_vision(msg, me, target);
	return 1;
}
