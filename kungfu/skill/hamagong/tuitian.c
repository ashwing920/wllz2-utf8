// tuitian.c 推天式

#include <ansi.h>

inherit F_SSERVER;

static int flag=0;

int perform(object me, object target)
{
	int damage,neili;
	string msg;

	if(!me->query("ouyangfeng_son")) return 0;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character()
	   || !me->is_fighting(target) || !living(target) )
		return notify_fail("推天式只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("hamagong", 1) < 250 )
		return notify_fail("你的蛤蟆功还不够熟练，不能使用推天式对敌！\n");

	if(objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「推天式」！\n");

	if((string)me->query_skill_mapped("force") != "hamagong")
		return notify_fail("你的内功中无此功夫。\n");

	if((string)me->query_skill_mapped("strike") != "hamagong")
		return notify_fail("你必须先将蛤蟆功运用于掌法之中才行。\n");

	if((int)me->query("max_neili") < 2500 )
		return notify_fail("你现在内力修为不够，无法运用推天式！\n");

	if((int)me->query("jingli") < 500)
		return notify_fail("你的精力不足以运用推天式！\n");

	neili = (int)me->query("max_neili") / 10;

	if((int)me->query("neili") < neili)
		return notify_fail("你现在内力不足，使不出蛤蟆功的推天式！\n");

	if((int)me->query_skill("strike", 1) < 250 )
		return notify_fail("你的掌法不够娴熟，使不出蛤蟆功的推天式！\n");

	if(me->query_str() < 30 )
		return notify_fail("你的力量太小，使不出用蛤蟆绝招！\n");

	me->clean_up_enemy();

	msg = HIG"\n$N气运丹田，身子平伏而下，猛的突然发出“哈”的一怒吼，整个人朝$n飞了过去！\n"NOR;

	if(random(me->query_skill("force")) > target->query_skill("force") /3 ){
		msg += HIM"$n被$N一惊，竟不知要如何是好，刚想闪身避开，说时迟那时快，只见$N双掌向前平推而出\n"
		"只听见“乓”的一声巨响，$N的双掌拍在了$n的胸前，落下了一双熏黑的手印。\n"NOR;
		damage = (int)me->query("max_neili") / 2;
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage / 3,me);
		me->add("neili",-neili);
		me->add("jingli",-500);
		me->start_busy(5);
		flag = 1;
	}
	else {
		msg += HIW"只见$N双掌向前平推而出，朝$n的胸前拍去，可是$n早已识破了$N的阴谋，\n"
		"急忙挥掌平推，正好与$N的双掌碰在一起，发出一阵震耳欲聋的巨响。\n"NOR;
		me->add("neili",- neili / 2);
		me->start_busy(3);
		flag = 0;
	}
	message_vision(msg, me, target);
	if(flag)
		COMBAT_D->report_status(target,1);
	else
		COMBAT_D->report_status(me,1);
	return 1;
}
