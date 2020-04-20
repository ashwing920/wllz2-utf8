// fanchang.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	int sp, dp;

	if ( target == me )
		target = offensive_target(me);

	if(environment(me)->query("no_fight"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能!\n");
	if(!objectp(target) || target->is_fight_npc())
		return notify_fail("你要攻击谁？\n");

	if( !me->is_fighting())
		return notify_fail("梵唱只能在战斗中使用。\n");
	if((int)me->query_skill("longxiang",1) < 120 )
		return notify_fail("你的龙象般若功功力不够，不能凝神攻击对方！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够，不能使用龙象般若功。\n");

	message_vision(HIW "$N面无表情，歌声如梵唱般贯入$n耳中！\n\n" NOR, me, target );

	sp = (int)me->query_skill("force") + (int)me->query_skill("mizongxinfa") + (int)me->query_skill("longxiang",1)/2;
	dp = (int)target->query_skill("force");
	
	me->add("neili", -200);
	if (( random(sp) > random(dp) ) || !living(target) ){
		tell_object(target, HIW " 你忽然觉得脑中一片空白，不由自主地随歌声舞蹈起来！\n" NOR);
		tell_object(me, HIB "你看到" + target->name() + "随着你的歌声手舞足蹈，十分可笑。\n" NOR);
		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)),me);
		me->start_busy(2);
		target->start_busy(random(3));
		me->set_temp("first_kill/"+target->query("id"), 1);
		if(!me->is_killing(target->query("id"))) me->fight_ob(target);
		if(!target->is_killing(me)) target->fight_ob(me);
	}
	else
	{	
		message_vision(HIY "可是$p不为$P歌声所动，定力果然不同凡响！\n" NOR, me, target);
		me->start_busy(4);
	}
	return 1;
}
