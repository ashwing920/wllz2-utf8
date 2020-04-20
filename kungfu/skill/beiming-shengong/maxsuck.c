// maxsuck.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me ) target = offensive_target(me);

	if( !me->is_fighting())
		return notify_fail("你必须在战斗中才能吸取他人丹元。\n");

	if( !objectp(target) || target->is_fight_npc() ||  (string)target->query("race") != "人类")
		return notify_fail("你要吸取谁的丹元？\n");

	if( !target->is_character() || target->is_corpse())
		return notify_fail("看清楚一点，那不是活物。\n");

	if((int)me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过丹元！\n");

	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才能施用北冥神功吸人丹元！\n");

	if((int)me->query_skill("beiming-shengong",1) < 120 )
		return notify_fail("你的北冥神功功力不够，不能吸取对方的丹元！\n");

	if((int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，不能使用北冥神功。\n");

	if((int)me->query("neili") > (int)me->query("max_neili") * 3)
		return notify_fail("你的内力已经远远超越了根本内力了。\n");

	if((int)me->query("max_neili") >= (int)me->max_neili())
		return notify_fail("你的内力似乎已经达到了瓶颈。\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() +"丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

	if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
		return notify_fail( target->name() +"的内功修为远不如你，你无法从他体内吸取丹元！\n");

	message_vision(HIG "$N全身一振，伸出右手，轻轻握在$n的手臂上。\n\n" NOR,me,target);

	sp = (int)me->query_skill("force") + (int)me->query_skill("dodge") + (int)me->query_skill("zhaixinggong",1)/2;
	dp = (int)target->query_skill("force") + (int)target->query_skill("dodge");

	me->set_temp("sucked", 1);

	if (( random(sp) > random(dp) ) || !living(target) ){
		tell_object(target, HIR "你只觉全身乏力，全身功力如融雪般消失得无影无踪！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);
		target->add("max_neili",  -1*(1+((int)me->query_skill("beiming-shengong", 1)-90)/5) );
		me->add("max_neili",1*(1+((int)me->query_skill("beiming-shengong", 1)-90)/5) );
		if((int)target->query("max_neili") <1) target->set("max_neili",0);
		if((int)me->query("neili") > (int)me->query("max_neili") * 3)
		me->set("neili",(int)me->query("max_neili") * 3);
		me->start_busy(4);
		target->start_busy(random(7));
		me->add("neili", -100);
		me->start_call_out((: call_other, __FILE__, "del_sucked", me, 10:),10);
	}
	else
	{
		message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
		me->start_busy(7);
		me->start_call_out((: call_other, __FILE__, "del_sucked", me, 20:),20);
	}

	return 1;
}

void del_sucked(object me)
{
	if((int)me->query_temp("sucked") )
	me->delete_temp("sucked");
}
