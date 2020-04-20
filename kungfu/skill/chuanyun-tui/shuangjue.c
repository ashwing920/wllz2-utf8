//lianhuan.c 连环 perform

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("拳腿双绝只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「拳腿双绝」！\n");

	if(me->query_skill_prepared("cuff") != "zhentian-quan"
	|| me->query_skill_prepared("leg") != "chuanyun-tui"
	|| me->query_skill_mapped("cuff") != "zhentian-quan"
	|| me->query_skill_mapped("leg") != "chuanyun-tui")
		return notify_fail("你现在无法使用「拳腿双绝」进行攻击！\n");

        if((int)me->query_skill("zhentian-quan", 1) < 100 )
		return notify_fail("你的震天拳不够娴熟，无法施展出拳腿双绝。\n");

	if((int)me->query_skill("cuff", 1) < 100 )
                return notify_fail("你的拳法不够娴熟，无法施展出拳腿双绝。\n");

	if((int)me->query_skill("leg", 1) < 100 )
                return notify_fail("你的腿法不够娴熟，无法施展出拳腿双绝。\n");

	if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("你的内功不够娴熟，无法施展出拳腿双绝。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( (int)me->query_skill("chuanyun-tui", 1) < 150 )
		return notify_fail("你的穿云腿不够娴熟，无法施展出拳腿双绝。\n");

	if( (int)me->query_skill("parry",1) < 100 )
                return notify_fail("你的招架不够娴熟，无法施展出拳腿双绝。\n");

        if ((int)me->query_skill("xuantian-force", 1) < 150)
                return notify_fail("你的玄天无极功火候不够，无法施展出拳腿双绝。\n");
	
	if( (int)me->query_dex() < 30 )
		return notify_fail("你的身法欠佳，无法施展出拳腿双绝。\n");

	if( (int)me->query_str() < 30 )
		return notify_fail("你的体魄不足，无法发挥出拳腿双绝的威力。\n");

	if( (int)me->query_int() < 30 )
		return notify_fail("你的悟性不够，无法领悟出拳腿双绝。\n");

        if((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够，无法施展出拳腿双绝。\n");

        if((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法施展出拳腿双绝。\n");

	message_vision(RED "$N一声清啸，拳脚齐施，使出昆仑绝学「拳腿双绝」迅捷无伦地攻向$n！\n"NOR,me, target);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		target->start_busy((int)me->query_skill("chuanyun-tui",1) / 60);
		damage = (int)me->query_skill("xuantian-force",1) + (int)me->query_skill("chuanyun-tui",1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", - 200);
		me->start_busy(1);

	message_vision(HIY"结果$n被$N的连环腿踢得晕头转向！\n"NOR,me, target);

	}
	 else {
	message_vision(HIY"可是$p看破了$P的企图，巧妙得躲了开去。\n"NOR,me, target);
		me->start_busy(3);
	}

	return 1;
}
