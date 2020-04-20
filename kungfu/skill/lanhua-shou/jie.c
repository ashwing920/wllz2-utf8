// jie.c　解穴

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	skill = (int)me->query_skill("lanhua-shou",1);

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

	if((int)me->query_skill("bibo-shengong",1) < 120)
		return notify_fail("你的碧波神功修为不够，无法为他人解穴！\n");

	if(skill < 120) 
		return notify_fail("你的兰花拂穴手不够纯熟，恐怕无法替人解穴。\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，恐怕无法冲开他人穴道。\n");

	if((int)me->query("neili") < 200 ) 
		return notify_fail("你的内力不足！\n");
		       
	me->clean_up_enemy();
	
	message_vision(HIC"$N默运内力，右手轻描淡写的向$n身上的气海穴点拍去。\n" NOR,me,target);
	
	if(target->query_condition("no_exert") > 1){
		message_vision(HIW"$n身子一轻，终于回过一口气了。\n"NOR,me,target);
		target->apply_condition("no_exert",0);
		me->add("neili",- 300);
		me->start_busy(2);
	}
	else {
		message_vision(WHT"可是好像什么用也没有。\n"NOR,me,target);
		me->add("neili",-100);
		me->start_busy(1);
	}
	return 1;
}
