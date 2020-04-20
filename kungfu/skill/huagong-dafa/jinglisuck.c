// jinglisuck.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if( target == me ) target = offensive_target(me);

	if(!me->is_fighting())
		return notify_fail("你只能在战斗中吸取他人的精力。\n");

	if( !objectp(target) || target->is_fight_npc() || (string)target->query("race") != "人类")
		return notify_fail("你要吸取谁的丹元？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活的。\n");

	if((int)me->query_temp("sucked"))
		return notify_fail("你刚刚吸取过丹元！\n");

	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才能施用化功大法吸人丹元！\n");

	if( (int)me->query_skill("huagong-dafa",1) < 120 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的丹元！\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if((int)target->query("max_jingli") <= 0)
		return notify_fail( target->name() +"丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

	if((int)target->query("jingli") < 100)
		return notify_fail( target->name() +"已经精力颓废，你已经无法从他体内吸取任何精力了！\n");

	if((int)me->query("max_jingli") >= me->max_jingli())
		return notify_fail("你的精力修为似乎已经达到了瓶颈了。\n");

	if((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		return notify_fail("你的精力已经超越了你所能承受的局限。\n");

	message_vision(HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,me,target);

	sp = (int)me->query_skill("force") + (int)me->query_skill("dodge") + (int)me->query_skill("zhaixinggong",1)/2;
	dp = (int)target->query_skill("force") + (int)target->query_skill("dodge");

	me->set_temp("sucked", 1);

	if (( random(sp) > random(dp) ) || !living(target) ){
		tell_object(target, HIR "你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
		target->add("max_jingli",- (int)me->query_skill("huagong-dafa",1) / 2);
		me->add("max_jingli",(int)me->query_skill("huagong-dafa",1) / 2);
		me->add("jingli",(int)me->query_skill("huagong-dafa",1) / 2);
		if((int)me->query("max_jingli") > me->max_jingli()) me->set("max_jingli",me->max_jingli());
		if((int)target->query("max_jingli") < 1) target->set("max_jingli",0);
		me->start_busy(random(5)+2);
		target->start_busy(random(7));
		me->add("neili", -100);
		me->start_call_out((:call_other,__FILE__,"del_sucked",me,2 :),2);
	}
	else
	{
		message_vision(HIY "可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(7);
		me->start_call_out((:call_other,__FILE__,"del_sucked",me,4:),4);
	}
	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
