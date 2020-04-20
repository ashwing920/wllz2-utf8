// chong.c

#include <ansi.h>

int exert(object me, object target)
{

	if(!target)
		return notify_fail("你要用真气为谁疗伤？\n");
	
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if((int)me->query_skill("bahuang-gong",1) < 200 )
		return notify_fail("你的八荒六合神功修为不够，无法冲开穴道。\n");

	if(target->is_busy())
		return notify_fail("你还是等"+ target->name()+"忙完了再说吧！\n");
	
	if((int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够。\n");

	if((int)me->query("neili") < ((int)me->query("max_neili") * 4 / 3)
	|| (int)me->query("neili") < 500 )
		return notify_fail("你体力的真气不够，恐怕无法将穴道冲开。\n");

	if((int)target->query("eff_qi") < (int)target->query("max_qi") / 5)
		return notify_fail( target->name() +"受伤过重，恐怕经受不起你的真气震荡！\n");

	if(target != me){
		message_vision(HIW"$N盘膝而坐，将全身的劲道与内力提起齐于丹田，脸上猛然间涨了个通红。\n"
		"忽听见$N一声暴喝：嗨. . .$N通红的双掌猛的往$n的背心轻轻拍去，将真气强行灌入$n的体内。\n"
		"$N头顶上冒出了缕缕清烟 ....过了许久，$n终于回了一口气，封住的穴道已经被$N冲开了。\n"NOR,me,target);
	}
	else {
		message_vision(HIW"$N盘膝而坐，将全身的劲道与内力提起齐于丹田，瞬间，只见$N脸上涨个通红。\n"
		"忽然，$N双手平举，一声暴喝：嗨. . .一股真气在$N身上迸发而出，泛起一道道尘埃。\n$N连忙回了一口气，封住的穴道已经被冲开了。\n" NOR,me);
	}
	if( target->query_condition("no_exert")){
		target->apply_condition("no_exert",0);
	}
	else if(target->query_condition("no_perform")){
		target->apply_condition("no_perform",0);
	}
	else if(target->query_condition("no_speak")){
		target->apply_condition("no_speak",0);
	}
	target->set("neili",0);
	target->revive_damage("qi",0);
	me->revive_damage("qi",0);
	me->start_busy(3);
	target->start_busy(3);
	me->add("neili",-500);
	return 1;
}
