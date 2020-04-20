// feeblebolt.c

#include <ansi.h>

inherit F_SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;

	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 50 )
		return notify_fail("你的法术不够高！\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展这个法术？\n");

	if((int)me->query("jingli") < 25 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("jing") < 10 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("jingli", -25);
	me->receive_damage("jing", 10);

	if( random(me->query("max_jingli")) < 50 ) {
		write("你失败了。\n");
		return 1;
	}
	msg = HIW "$N口中喃喃地念著咒文，左手一挥，手中聚起一团白光射向$n！\n\n" NOR;

	ap = me->query_skill("spells");
	extradam = ap/2;

	dp = target->query_skill("dodge");
	ap = (ap/10) * (ap/10) * (ap/10) / 3 + me->query("combat_exp") /100 ;
	dp = (dp/10) * (dp/10) * (dp/10) / 3 + target->query("combat_exp") / 100;
	if(target->query("max_jing") > 0)
		dp = dp / target->query("max_jing") * target->query("jing");

	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_jingli") / 40 + random((int)me->query("eff_jing") / 20) + random(extradam);
		damage -= (int)target->query("max_jingli") / 30 + random((int)me->query("eff_jing") / 15);
		if( damage > 0 ) {
			msg +=  HIR "结果「嗤」地一声，白光从$p身上透体而过，拖出一条长长的黑气直射到\n"
				"两三丈外的地下！\n" NOR;
			target->receive_damage("jing", damage, me);
			target->receive_wound("jing", damage/3, me);
			me->improve_skill("blackart", 1, 1);
		} else
			msg += "结果「嗤」地一声，白光从$p身上透体而过，无声无息地钻入地下！\n";
	} else
		msg += "但是被$n躲开了。\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

	if( !target->is_fighting(me) ) {
		me->kill_ob(target);
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	me->start_busy(2);
	return 1;
}

