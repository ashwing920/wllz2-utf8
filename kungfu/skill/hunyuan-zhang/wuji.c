// wuji.c 混元无极
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hunyuan-zhang",1);
	if(!(me->is_fighting() ))
		return notify_fail("「混元无极」只能对战斗中的对手使用。\n"); 
	if(objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");
	if(skill < 120)
		return notify_fail("你的「混元掌」等级不够, 不能使用「混元无极」！\n");

	if( me->query("neili") < 300)
		return notify_fail("你的内力不够，无法运用「混元无极」！\n");
 
	msg = HIC "$N潜运「混元无极」，双拳挟着隐隐的风雷之声向$n击去。\n"NOR;
	message_vision(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp ){
		if(userp(me))
		me->add("neili",-300);
		msg = HIG "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili") / 2;

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi") / 2;

		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me))
		me->add("neili",- 300);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
