// xijing.c for xixing-force

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

	if(!me->is_fighting())
		return notify_fail("你必须在战斗中才可以吸取他人的精力。\n");

	if( !objectp(target) || target->is_fight_npc())
		return notify_fail("你要吸取谁的精神？\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活的。\n");

	if(objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才可以吸取他人的精力。\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过精神！\n");

	if( (int)me->query_skill("xixing-force",1) < 120 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的精神。\n");

	if( (int)me->query("neili",1) < 100 )
		return notify_fail("你的内力不够，不能使吸星大法。\n");

	if( (int)target->query("jing") < (int)target->query("max_jing") / 5 )
		return notify_fail( target->name() +"已经精神涣散，你已经无法从他体内吸取精力了！\n");

	message_vision(HIR "$N突然神情大变，双掌迅速的对准$n的太阳穴拍了过来！\n\n" NOR,me, target );

	me->set_temp("first_kill/"+ target->query("id"),1);
	
	if( !target->is_killing(me->query("id")) )
	me->fight_ob(target);
	target->kill_ob(me);

	sp = (int)me->query_skill("force") + (int)me->query_skill("dodge") + (int)me->query("kar");
	dp = (int)target->query_skill("force") + (int)target->query_skill("dodge") + (int)me->query("kar");

	me->set_temp("sucked", 1);
	if( random(sp) > random(dp) ){
		tell_object(target, HIR "你猛觉额角两侧如针刺般剧痛，一切都不知道了.....\n" NOR);
		tell_object(me, HIG "你觉得" + target->name() + "的精力自手掌源源不绝地流了进来。\n" NOR);
		target->receive_damage("jing", (int)me->query_skill("xixing-force"),me);
		me->add("jing", (int)me->query_skill("xixing-force") );
		me->start_busy(random(3));
		target->start_busy(random(3));
		me->add("neili", -5);
		if( (int)me->query("jing") > (int)me->query("eff_jing")){
			me->set("jing",(int)me->query("eff_jing"));
		}
		me->start_call_out((: call_other, __FILE__, "del_sucked", me, 2:),2);
	}
	else
	{
		message_vision(HIY "可是$p看破了$P的企图，机灵地闪了开去。\n" NOR, me, target);
		me->start_busy(3);
		me->start_call_out((: call_other, __FILE__, "del_sucked", me, 4:),4);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}
