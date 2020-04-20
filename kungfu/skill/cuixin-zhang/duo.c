// /kungfu/skill/gu.c 夺魄催心

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg,dodge_skill;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「夺魄催心」只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「夺魄催心」！\n");

	if((int)me->query_skill("cuixin-zhang", 1) < 180 )
		return notify_fail("你的催心掌不够娴熟，无法运用「夺魄催心」。\n");

	if((int)me->query_skill("bibo-shengong", 1) < 150 )
		return notify_fail("你的碧波神功火候不够，无法发挥「夺魄催心」的威力！\n");

	if((string)me->query_skill_mapped("force") != "bibo-shengong")
		return notify_fail("你必须借助碧波神功的来发挥催心掌的威力。\n");

	if( (int)me->query("neili") < 500)
		return notify_fail("你现在内力太弱，不能使用「夺魄催心」！\n");

	if(target->query_condition("cuixin_poision"))
		return notify_fail(target->name()+"已经失魂落魄，精神恍惚！\n");

	me->clean_up_enemy();

	skill = (int)me->query_skill("qimen-wuxing",1) / 2;

	msg = HIB"$N一声怪啸，形如飘风，左掌已如风行电挚般拍出，掌未到，风先至，迅猛已极。";
	msg += "那掌风越来越大，越来越猛，直逼$n的胸口袭去。\n"NOR;
	if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3 ){
		msg += HIR"\n$n才知不对，正要闪开，却已被$N的掌风击中胸前，不禁“哇”的一声吐出一口鲜血，"
		"顷刻间变得双目无神，精神恍惚，不知如何是好！\n"NOR;
		target->apply_condition("cuixin_poison",skill);
		me->add("neili",-500);
		me->start_busy(2);
	}
	else
	{
		msg += HIW"\n怎料$n早有准备，连忙反掌接招，$N和$n的双掌碰在一起，发出一阵震耳欲聋的剧响。\n"NOR;
		me->start_busy(4);
		me->add("neili",-500);
	}
	message_vision(msg, me, target);
	return 1;
}
