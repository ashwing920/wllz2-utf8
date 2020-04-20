// qisuck.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me ) target = offensive_target(me);

	if( !objectp(target) || target->is_fight_npc() || (string)target->query("race") != "人类")
		return notify_fail("你要吸取谁的真气？\n");

	if(!me->is_fighting())
		return notify_fail("你只能在战斗中吸取他人的真气。\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活的。\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过真气！\n");

	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才能施用化功大法吸人真气！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 120 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的真气。\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("qi") < 30 )
		return notify_fail( target->name() +"已经真气涣散，你已经无法从他体内吸取真气了！\n");

	message_vision(HIR "$N突然诡异的一笑，双手一扬，拇指对准$n的掌心按了过来！\n\n" NOR,me, target );

	sp = (int)me->query_skill("force") + (int)me->query_skill("dodge") + (int)me->query_skill("zhaixinggong",1)/2;
	dp = (int)target->query_skill("force") + (int)target->query_skill("dodge");

	me->set_temp("sucked", 1);

	if (( random(sp) > random(dp) ) || !living(target) )
	{
		tell_object(target, HIR "你突然觉得全身真气自手掌奔涌而出，四肢无力，再也使不出劲来！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的真气自手掌源源不绝地流了进来。\n" NOR);
		target->receive_damage("qi",(int)me->query_skill("huagong-dafa",1),me);
		me->add("qi", (int)me->query_skill("huagong-dafa",1));
		me->add("eff_qi",(int)(me->query_skill("huagong-dafa", 1)*2/3) );
		if((int)me->query("eff_qi") > (int)me->query("max_qi") )
		me->set("eff_qi", (int)me->query("max_qi"));
		if((int)me->query("qi") > (int)me->query("eff_qi"))
		me->set("qi",(int)me->query("eff_qi"));
		me->start_busy(2);
		target->start_busy(random(2));
		me->add("neili", -50);
		me->start_call_out((: call_other,__FILE__,"del_sucked",me,2:),2);
	}
	else
	{
		message_vision(HIY "可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(2);
		me->start_call_out((: call_other,__FILE__,"del_sucked",me,4:),4);
	}
	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
