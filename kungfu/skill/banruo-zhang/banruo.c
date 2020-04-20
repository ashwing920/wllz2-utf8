// fenfei.c 般若掌力
 
#include <ansi.h>
 
inherit F_SSERVER;

void banruo2(object me,object target);
void banruo3(object me,object target);

int perform(object me)
{
	string msg;
	object weapon, target;
	int ap, dp, damage;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「般若掌力」只能在战斗中使用。\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力修为连小般若掌力都打不出来！\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你现在的内力不足。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("拿着武器怎么使「般若掌力」？\n");

	if((int)me->query_skill("strike",1) < 120)
		return notify_fail("你的掌法还不到家，连小般若掌力都打不出来！\n");

	if((int)me->query_skill("force",1) < 120)
		return notify_fail("你内功的修为不够，连小般若掌力都打不出来！\n");

	if((string)me->query_skill_mapped("strike") != "banruo-zhang") 
		return notify_fail("你没有激发般若掌，无法使用般若掌力\n");

	if((int)me->query_temp("banruo"))
		return notify_fail("你已经在运用般若掌力了。\n");

	msg = HIY "$N突然运气于掌，聚起「小般若掌力」，右掌带一层淡淡的白雾直直拍向$n的胸前！\n\n"NOR;
	message_vision(msg, me, target);

	ap = (((int)me->query("combat_exp"))*((int)me->query_dex()));
	dp = (((int)target->query("combat_exp"))*((int)target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		msg = HIR "$n心神一慌，一个躲闪不及，被$N的单掌实实在在的印在胸膛，$n的胸膛立刻就塌了下去！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-300);
		damage = 100 + (int)me->query_skill("strike") + random((int)me->query_skill("force"));
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage / 2 ,me);
		COMBAT_D->report_status(target);
		me->start_busy(3);
	}
	else
	{
		msg = HIG "只见$n神色一凛，不敢硬接，一个翻身及时的退出战圈，躲开了$N凌厉的攻势！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-100);
		me->start_busy(3);
	}
	call_out("banruo2", 3, me,target);
	return 1;
}

void banruo2(object me,object target)
{
	string msg;
	object weapon;
	int ap, dp, damage;

	if(!me || !target) return;
	if(!me->is_fighting()|| !living(me) ) return;
	if((int)me->query("max_neili") < 1000 ) return;
	if((int)me->query("neili") < 500 ) return;
	if(objectp(weapon = me->query_temp("weapon"))) return;
	if((int)me->query_skill("strike",1) < 200) return;
	if((int)me->query_skill("force",1) < 200) return;
	if((string)me->query_skill_mapped("strike") != "banruo-zhang")  return;

	msg = WHT "$N双掌一错，白色劲气已然布满全身，风雷之声渐起，这第二掌「大般若掌力」猛然拍出！\n\n"NOR;
	message_vision(msg, me, target);

	ap = (((int)me->query("combat_exp"))*((int)me->query_dex()));
	dp = (((int)target->query("combat_exp"))*((int)target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if((ap * 4 / 3) > dp )
	{
		msg = HIR "$n正瞠目间，$N双掌已到了胸前，内劲一吐，$n立时口喷鲜血，倒飞出三丈有余！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-500);
		damage = 200 + (int)me->query_skill("strike") + 2 * random((int)me->query_skill("force"));
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage / 2,me);
		COMBAT_D->report_status(target);
		me->start_busy(3);
	}
	else
	{
		msg = HIG "$n躲无可躲，就地一滚，非常狼狈的堪堪躲开了这第二掌。\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-200);
		me->start_busy(3);
	}
	call_out("banruo3", 3, me,target);
	return;
}

void banruo3(object me,object target)
{
	string msg;
	object weapon;
	int ap, dp, damage;

	if(!me || !target) return;
	if(!me->is_fighting()|| !living(me) ) return;
	if((int)me->query("max_neili") < 1500 ) return;
	if((int)me->query("neili") < 700 ) return;
	if(objectp(weapon = me->query_temp("weapon"))) return;
	if((int)me->query_skill("strike",1) < 300) return;
	if((int)me->query_skill("force",1) < 300) return;
	if((string)me->query_skill_mapped("strike") != "banruo-zhang")  return;
 
	msg = HIW "$N神色凝重，周身七尺劲气涌动，突然大喝一生，这少林般若禅功的无上功力终化作「龙象般若掌力」汹涌而出！\n\n"NOR;
	message_vision(msg, me, target);

	ap = (((int)me->query("combat_exp"))*((int)me->query_dex()));
	dp = (((int)target->query("combat_exp"))*((int)target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if((ap * 3 / 2) > dp)
	{
		msg = HIR "$n似一片枯叶，被龙象般若掌力的汹涌劲气包围、卷起、压扁、抛下，重重的摔在地上，眼看是不行了！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-700);
		damage = 300 + (int)me->query_skill("strike") + 3 * random((int)me->query_skill("force"));
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi", damage / 2,me);
		COMBAT_D->report_status(target);
		me->start_busy(random(10));
	}
	else
	{
		msg = HIG "$n一闭眼，朝$N的反方向似一颗流星般急退而出，总算从鬼门关上拣回了一条命。\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-300);
		me->start_busy(5);
	}
	return;
}
