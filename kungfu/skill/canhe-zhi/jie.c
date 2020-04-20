// jie.c　解穴

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	skill = (int)me->query_skill("canhe-zhi",1);

	if( !target)
		return notify_fail("你要替谁解穴？\n");

	if( target == me)
		return notify_fail("你无法帮自己解穴。\n");

	if(me->is_fighting())
		return notify_fail("战斗中无法替人解穴。\n");

	if(target->is_fighting())
		return notify_fail(target->name() +"正在战斗，你根本无从下手。\n");

	if(me->query_temp("weapon"))
		return notify_fail("你必须空手才能解穴。\n");

	if((int)me->query_skill("shenyuan-gong",1) < 200)
		return notify_fail("你的神元功修为不够，无法使用封穴式！\n");

	if(skill < 200) 
		return notify_fail("你的参合指还不够纯熟，恐怕无法替人解穴。\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，恐怕无法冲开他人穴道。\n");

	if((int)me->query("neili") < 500 ) 
		return notify_fail("你的内力不足！\n");
		       
	me->clean_up_enemy();
	message_vision(HIC"$N默运内力，传于指间，两指合并，迅速的往$n身上的穴道点去。\n" NOR,me,target);
	
	if(target->query_condition("canhe_smile") > 1){
		message_vision(HIW"$n身子轻轻一晃，身上的笑穴被$N解开了。\n"NOR,me,target);
		target->apply_condition("canhe_smile",0);
		me->add("neili",- 300);
		me->start_busy(2);
	}
	else if(target->query_condition("no_speak") > 1){
		message_vision(HIW"$n回了一口气，被封闭的哑穴被$N解开了。\n"NOR,me,target);
		target->apply_condition("no_speak",0);
		me->add("neili",- 200);
		me->start_busy(2);
	}
	else {
		message_vision(WHT"可是$n仍旧丝毫不变，显然$N的解穴大法毫无作用。\n"NOR,me,target);
		me->add("neili",-100);
		me->start_busy(1);
	}
	return 1;
}
