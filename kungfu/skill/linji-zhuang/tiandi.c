// tiandi.c

#include <ansi.h>

int exert(object me, object target)
{

	if(me->is_fighting())
		return notify_fail("你无法在战斗中运用临济十二庄。\n");

	if(me->is_busy())
		return notify_fail("你正忙着哪！\n");

	if((int)me->query_skill("linji-zhuang", 1) < 40)
		return notify_fail("你的临济十二庄修为还不够。\n");

	if((int)me->query("neili") < 30 )
		return notify_fail("你的真气不够。\n");

	if((string)me->query("family/family_name") != "峨嵋派")
		return notify_fail("可能缺乏师长指点，你运起临济十二庄，可是武功却毫无丁点长进。\n");

	if((int)me->query("eff_qi") >= (int)me->query("max_qi")
	&& (int)me->query("eff_jing") >= (int)me->query("max_jing"))
		return notify_fail("你没有受伤。\n");

	if((int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write(HIY"你习地而做，默念临济十二庄「天地」诀，运起临济十二庄功开始疗伤。\n" NOR);
	message_vision(HIW"只见$N吐出一口瘀血，脸色看起来好多了。\n" NOR,me);
	if((int)me->query("eff_qi") < (int)me->query("max_qi"))
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5);
	if((int)me->query("eff_qi") > (int)me->query("max_qi"))
	me->set("eff_qi",(int)me->query("max_qi"));
	if((int)me->query("eff_jing") < (int)me->query("max_jing"))
	me->receive_curing("jing", 10 + (int)me->query_skill("force")/5);
	if((int)me->query("eff_jing") > (int)me->query("max_jing"))
	me->set("eff_jing",(int)me->query("max_jing"));
	me->add("neili", -30);
	me->set("jiali", 0);
	me->start_busy(2);
	return 1;
}
