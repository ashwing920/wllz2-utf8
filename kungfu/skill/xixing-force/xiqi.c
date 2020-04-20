// xiqi.c for xixing-force

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

	if(!me->is_fighting())
		return notify_fail("你必须在战斗中才可以吸取他人的真气。\n");

	if( !objectp(target) || target->is_fight_npc())
		return notify_fail("你要吸取谁的体力？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活的。\n");

	if(objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才可以吸取他人的真气。\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过气！\n");

	if( (int)me->query_skill("xixing-force",1) < 120 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的内力！\n");

	if( (int)me->query("neili",1) < 100 )
		return notify_fail("你的内力不够，不能使用吸星大法。\n");

	if( (int)target->query("qi") <= 0 )
		return notify_fail( target->name() +"没有任何气血！\n");

	if( (int)target->query("qi") < (int)target->query("max_qi") / 50 )
		return notify_fail( target->name() +"已经奄奄一息了！\n");

	message_vision(HIR "$N脸色一变，右掌突然指出，猛地对准$n的膻中大穴点了上去！\n\n" NOR,me, target );

	me->set_temp("first_kill/"+ target->query("id"),1);
	if( !target->is_killing(me->query("id")))
	target->fight_ob(me);
	me->kill_ob(target);
	
	sp = (int)me->query_skill("force") + (int)me->query_skill("dodge") + (int)me->query("kar");
	dp = (int)target->query_skill("force") + (int)target->query_skill("dodge") + (int)me->query("kar");

	me->set_temp("sucked", 1);

	if( random(sp) > random(dp) )
	{
		tell_object(target, HIR "你顿觉膻中微痛，如同被尖针刺了个小孔，全身气力飞泄而出！\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的气力自手掌源源不绝地流了进来。\n" NOR);
		target->add("qi", -1*(int)me->query_skill("xixing-force"));
		me->add("qi", (int)me->query_skill("xixing-force"));
		me->start_busy(random(4));
		target->start_busy(random(4));
		me->add("neili", -60);
		if( (int)me->query("qi") > (int)me->query("eff_qi")) {
			me->set("qi",(int)me->query("eff_qi"));
		}
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
	if(!me) return;
	if ( me->query_temp("sucked"))
	me->delete_temp("sucked");
}
