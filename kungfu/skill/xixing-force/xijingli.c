// neilisuck.c

#include <ansi.h>
#include <human.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

	if( !me->is_fighting())
		return notify_fail("你必须在战斗中才能吸取别人的精力。\n");

	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活的。\n");

	if( !objectp(target) || target->is_fight_npc())
		return notify_fail("你要吸取谁的精力？\n");

	if(objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才可以吸取他人的精力。\n");

	if((int)me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过精力！\n");

	if((int)me->query_skill("xixing-force",1) < 120 )
		return notify_fail("你的吸星大法功力不够，不能吸取对方的精力！�n");

	if((int)me->query("neili") < 100 )
		return notify_fail("你的内力不够，不能使用吸星大法。\n");

	if((int)me->query("max_jingli") >= me->max_jingli())
		return notify_fail("你的精力修为似乎已经达到了瓶颈了。\n");

	if((int)target->query("max_jingli") <= 0 )
		return notify_fail( target->name() + "没有任何精力！\n");

	if((int)target->query("jingli") < 100 )
		return notify_fail( target->name() +"已经精力颓废，你已经无法从他体内吸取任何精力了！\n");

	me->set_temp("sucked", 1);

	message_vision(HIR"$N身法陡然加快，右掌直出，猛地对准$n的膻中大穴按了上去！\n" NOR,me,target);

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("xixing-force",1)/2;
	dp = target->query_skill("force") + target->query_skill("dodge");

	if(( random(sp) > random(dp) ) || !living(target) ){
		tell_object(target, HIR"你顿觉全身乏力，头昏脑胀，眼前依稀晃动着"+ me->query("name")+"的身影！！\n" NOR);
		tell_object(me,HIW"你觉得" + target->name() + "的精力自指尖源源不绝地流了进来。\n" NOR);
		target->add("jingli", -1*((int)me->query_skill("xixing-force") + target->query("jiali")));
		if ( target->query("jingli") < 1 ) target->set("jingli",0);
		me->add("jingli", (int)me->query_skill("xixing-force"));
		me->add("max_jingli", (int)me->query_skill("xixing-force"));
		if( me->query("max_jingli") > me->max_jingli())
		me->set("max_jingli",me->max_jingli());
		me->start_busy(random(5));
		target->start_busy(random(4));
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
