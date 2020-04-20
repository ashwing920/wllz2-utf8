//duan.c -夺命三斧之「断云斩」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「断云斩」。\n");

	if( (int)me->query_skill("duanyun-fu",1) < 120)
		return notify_fail("你目前功力还使不出「断云斩」。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够。\n");

	me->add("neili",- 200);
	msg = HIC"$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一
	道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！\n"NOR;
	me->start_busy(1);

	if( random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/4 ) {
	target->start_busy( (int)me->query_skill("duanyun-fu") / 120 );
	damage = (int)me->query_skill("duanyun-fu", 1)+(int)me->query_skill("axe",1)/2;
	damage = damage/2 + random(damage);

	target->receive_damage("qi",damage,me);
	msg += RED"只见$n被$N一斧砍中，胸前裂开一道深深的伤口，血如箭般喷射而出！\n"NOR;
	} else {
	msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}
