// yi.c 圣火令法「夺」字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("此攻击只能对战斗中的对手使用。\n");

	if(target->is_busy() )
		return notify_fail(target->name() + "已在全力化解自已的招数，你可以放胆的击！\n");

	if(!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("对方没有使用武器。\n");

	if((int)me->query_skill("shenghuo-shengong",1) < 120)
		return notify_fail("你的圣火神功不够娴熟，对圣火令发的「夺」字诀也只是一知半解。\n");

	if((int)me->query_skill("shenghuo-ling", 1) < 120 )
		return notify_fail("你的圣火令法还不够娴熟，不会使用「夺」字诀。\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的内力不够！\n");

	if((int)me->query_con() < 30 )
		return notify_fail("「夺」字诀需要很高的内功，才能出奇不异的把对方的兵器夺下来。\n");

	msg = CYN"$N举起令牌，双手一振，令牌已搭在$n的兵器上，企图以圣火令法「夺」字诀把$n的兵器夺下。\n"NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3
	&& me->query("neili") > random(target->query("neili"))) {
		msg += HIY "\n结果$p的兵器被$P的令牌一压一带，$p兵器已被$P夺下！\n" NOR;
		if(weapon->query("ownmake")) {
			weapon->unequip();
		} else {
			weapon->move(me);
		}
		me->add("neili", -200);
		me->start_busy(2);
		target->start_busy(1);
	}
	else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(1);
		me->add("neili", -100);
	}
	message_vision(msg, me, target);

	return 1;
}
