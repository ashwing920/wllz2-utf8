// break 玉石俱焚
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;

	damage = (int)me->query_skill("zhemei-shou",1) + (int)me->query_skill("force");
	damage = damage + me->query("jiali");

	if(!target ) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「玉石俱焚」只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「玉石俱焚」！\n");

	if( (int)me->query_skill("zhemei-shou", 1) < 200 )
		return notify_fail("你的天山折梅手不够娴熟，不会使用「玉石俱焚」！\n");

	if((int)me->query_skill("beiming-shengong",1) < 200
	&& me->query("family/family_name") == "逍遥派")
		return notify_fail("你的北冥神功不够娴熟，无法领会天山折梅手的要诀！\n");

	if((int)me->query_skill("bahuang-gong",1) < 200
	&& me->query("family/family_name") == "灵鹫宫")
		return notify_fail("你的八荒六合神功不够娴熟，无法领会天山折梅手的要诀！\n");

	if((string)me->query_skill_mapped("hand") != "zhemei-shou")
		return notify_fail("你没有激发天山折梅手为手法攻击，无法使用「玉石俱焚」！\n");

	if((string)me->query_skill_mapped("unarmed") != "zhemei-shou")
		return notify_fail("你没有激发天山折梅手为拳脚攻击，无法使用「玉石俱焚」！\n");

	if( me->query("jiali") < 1)
		return notify_fail("你没有设置加力，运用「玉石俱焚」将会毫无作用！\n");

	if((int)me->query("neili", 1) < 800 )
		return notify_fail("你现在内力太弱，不能使用「玉石俱焚」！\n");

	me->clean_up_enemy();
	message_vision(HIC"$N默运"+ to_chinese(me->query_skill_mapped("force"))+"，使天山折梅手中的绝技「玉石俱焚」，一手高举拍向$n的天灵盖。\n"NOR,me,target);
	if(random(me->query("combat_exp")) > target->query("combat_exp") / 3 ){
		me->start_busy(3);
		target->receive_damage("jing",damage*5,me);
		target->receive_wound("jing", damage*5,me);
		me->add("neili", -400);
		if(damage < 40)
			message_vision(HIY"结果$p被$P一击命中，立刻头昏目眩，眼花缭乱。\n\n"NOR,me,target);
		else if(damage < 80)
			message_vision(HIY"结果$p被$P一击命中，眼前一黑，差点昏了过去。\n\n"NOR,me,target);
		else if(damage < 160)
			message_vision(HIR"结果$p被$P一击命中，嘴角流出了一口乌黑的淤血。\n\n"NOR,me,target);
		else
			message_vision(HIR"结果$p被$P一击命中，“扑”的喷了一口鲜血。\n\n"NOR,me,target);
			COMBAT_D->report_status(target);
	}
	else
	{
		me->start_busy(3);
		me->add("neili",- 300);
		message_vision(CYN"可是$p看破了$P的企图，身形一转，反掌回击。\n"NOR,me,target);
	}
	if( living(me) && living(target)
	&& me->is_fighting(target)
	&& target->is_fighting(me)){
		call_out("break2",1,me,target,damage);
	}
	return 1;
}
void break2(object me,object target,int damage)
{
	if(!me || !target || !living(me) || !living(target)
	|| !me->is_fighting(target) || !target->is_fighting(me)
	|| me->query("neili") < 400 || me->query_temp("weapon")
	|| environment(me) != environment(target)) return;

	me->clean_up_enemy();
	message_vision(HIC"\n紧接着$N运起"+ to_chinese(me->query_skill_mapped("dodge"))+"，一个快步转身迅速窜向$n身后，向$n后心又是一掌！\n"NOR,me,target);
	if(random(me->query("combat_exp")) > target->query("combat_exp") / 4 ){
		me->start_busy(5);
		target->receive_damage("qi",damage*5,me);
		target->receive_wound("qi",damage*5,me);
		me->add("neili", -400);
		if( damage < 40 )
			message_vision(HIR"结果$p被$P掌风打在后背，闷哼一声。\n\n"NOR,me,target);
		else if( damage < 80 )
			message_vision(HIR"结果$p被$P以掌风打在后背，「嘿」地一声差点扑倒向前。\n\n"NOR,me,target);
		else if( damage < 160 )
			message_vision(HIR"结果$p被$P以掌风打在后背，有如受到一记重锤，连进五六步，差点摔了个趔趄！\n\n"NOR,me,target);
		else
			message_vision(HIR"结果$p被$P的掌风打在后背，哇的又吐出一口鲜血！\n\n"NOR,me,target);
			COMBAT_D->report_status(target);
	}
	else {
		me->start_busy(5);
		me->add("neili",- 300);
		message_vision(CYN"$p连忙运起"+ to_chinese(target->query_skill_mapped("dodge"))+"，侵刻间跳开数丈之外。\n"NOR,me,target);
	}
	return;
}
