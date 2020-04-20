// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{

	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( target == me) {
		message_vision(HIY"$N盘腿坐下，默运内力，将真气逼于丹田，开始运功疗伤。\n"NOR,me);
		message_vision(HIW"渐渐的，$N的气色看起来好了许多，精神也得到了恢复。\n"NOR,me);
	}
	else {
		message_vision(
		HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );
	}

	target->receive_curing("jing", 10 + (int)me->query_skill("force")/3 );
	target->add("jing", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
	me->add("neili", -10);
	me->set("jiali", 0);
	return 1;
}
