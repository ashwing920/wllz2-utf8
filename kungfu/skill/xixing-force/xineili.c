// xineili.c for xixing-force

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

	if(!me->is_fighting())
		return notify_fail("你必须在战斗中才可以吸取他人的内力。\n");

	if( !objectp(target) || target->is_fight_npc())
		return notify_fail("你要吸取谁的内力？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活的。\n");

	if(objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才可以吸取他人的内力。\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过内力！\n");

	if( (int)me->query_skill("xixing-force",1) < 120 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！�n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用吸星大法。\n");

	if((int)me->query("neili") > (int)me->query("max_neili") * 4)
		return notify_fail("你的内力已经远远超越了根本内力了。\n");

	if( (int)target->query("max_neili") <= 0 )
		return notify_fail( target->name() +"没有任何内力！\n");

	if( (int)target->query("neili") < (int)target->query("max_neili") / 10 )
		return notify_fail( target->name() +"已经内力涣散，你已经无法从他体内吸取任何内力了！\n");

	message_vision(HIR "$N脸色一变，右掌突然指出，猛地对准$n的膻中大穴点了上去！\n\n" NOR,me, target );

	if( !target->is_killing(me->query("id")) ) target->fight_ob(me);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query("con");
	dp = target->query_skill("force") + target->query_skill("dodge") + me->query("con");

	me->set_temp("sucked", 1);

	if( random(sp) > random(dp) )
	{
		tell_object(target, HIR "你顿觉膻中微痛，如同被尖针刺了个小孔，全身内力如水银般循孔飞泄而出！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);
		target->add("max_neili",-1 * (int)me->query_skill("force"));
		if((int)target->query("max_neili") <1) target->set("max_neili",0);
		target->add("neili", -1 * (int)me->query_skill("force"));
		if((int)target->query("neili") <1) target->set("neili",0);
		me->add("neili",(int)me->query_skill("force"));
		if((int)me->query("max_neili") < (int)me->max_neili())
		me->add("max_neili",1*(1+((int)me->query_skill("xixing-force",1)-90)/5));
		me->start_busy(random(4));
		target->start_busy(random(4));
		me->add("neili", -10);
		if((int)me->query("neili") > (int)me->query("max_neili") * 4)
		me->set("neili",(int)me->query("max_neili") * 4);
		me->start_call_out((: call_other, __FILE__, "del_sucked", me, 2:),2);
	}
	else
	{
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->start_busy(4);
		me->start_call_out((: call_other, __FILE__, "del_sucked", me, 4:),4);
	}

	return 1;
}
void del_sucked(object me)
{
	if ( me->query_temp("sucked"))
	me->delete_temp("sucked");
}
