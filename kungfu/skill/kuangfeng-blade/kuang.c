//kuang.c -「狂风二十一式」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「狂风二十一式」。\n");
		
	if( (int)me->query_skill("kuangfeng-blade",1) < 80)
		return notify_fail("你目前功力还使不出「狂风二十一式」。\n");
		
	if( (int)me->query("neili") < 300)
		return notify_fail("你的内力不够。\n");
	
	me->add("neili", -300);

	msg = HIC"$N淡然一笑，本就快捷绝伦的刀法骤然变得更加凌厉！就在这一瞬之间，"+
	"$N已劈出二十一刀！刀夹杂着风，风里含着刀影！$n只觉得心跳都停止了！\n"NOR;

	me->start_busy(2);
	me->clean_up_enemy();
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
	target->start_busy( (int)me->query_skill("kuangfeng-blade") / 20 );
	damage = (int)me->query_skill("kuangfeng-blade", 1)+(int)me->query_skill("blade", 1)/2;
	damage = damage + random(damage);
	target->receive_damage("qi", damage,me);
	target->receive_wound("qi", damage/6,me);
	msg += RED"只见$n已被$N切得体无完肤，血如箭般由全身喷射而出！\n"NOR;
	} else {
	msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

