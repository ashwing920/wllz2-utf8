// yinyang.c

#include <ansi.h>

int exert(object me)
{
	int nh, improve;

	nh = (int)me->query_skill("linji-zhuang");
	improve = nh * 3 / 2;

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中运用临济十二庄。\n");

	if (me->is_busy() )
		return notify_fail("你正忙着哪！\n");

	if ((int)me->query_skill("linji-zhuang", 1) < 120)
		return notify_fail("你的临济十二庄修为还不够。\n");

	if((string)me->query("family/family_name") != "峨嵋派")
		return notify_fail("可能缺乏师长指点，你运起临济十二庄，可是武功却毫无丁点长进。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( me->query_temp("yun_yinyang"))
		return notify_fail("你正在运用临济十二庄的「阴阳」字决！\n");

	write(HIW"你暗运阴阳两庄，吸取阴阳两气，聚精成力，顿觉气力倍增。\n"NOR, me);

	message_vision(HIW"只见$N稍显疲乏，但转瞬间便精神抖擞。\n"NOR,me);

	me->add("max_jingli", improve);
	me->add("jingli", improve);
	me->add_temp("apply/spirituality",(int)me->query("spi"));
	me->add_temp("apply/constitution",(int)me->query("con"));
	me->set_temp("yun_yinyang", 1);
	me->add("neili", - 150);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2);
	return 1;
}
void remove_effect(object me, int improve)
{
	me->add("max_jingli",- improve);
	me->add("jingli",- improve);
	me->add_temp("apply/spirituality",-(int)me->query("spi"));
	me->add_temp("apply/constitution",-(int)me->query("con"));
	me->delete_temp("yun_yinyang");
	tell_object(me, HIR"你的临济十二庄「阴阳」字决运功完毕，看起来你脸色好多了。\n"NOR);
}
