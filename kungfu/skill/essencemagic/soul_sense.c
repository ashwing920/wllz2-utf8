// soul_sense.c - 灵识神通

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
	int lvl;

	lvl = (int) me->query_skill("essencemagic",1);

	if ( lvl <= 120)
		return notify_fail("你的八识神通不够娴熟，无法使用灵识神通。\n");

	if( me->query("jingli") < lvl )
		return notify_fail("你的灵力不够！\n");

	if( me->query("jing") <= lvl )
		return notify_fail("你的精神不好，无法使用灵识神通！\n");

	if((int)me->query_temp("soul_sense"))
		return notify_fail("你已经施展灵识神通了。\n");

	me->add("jingli",-lvl);
	me->receive_damage("jing",lvl);
	me->add_temp("apply/dodge",lvl);
	me->set_temp("soul_sense",1);

	message_vision(HIW "$N微一凝神，闭著眼睛，使出八识神通中的灵识神通....\n" NOR, me);
	me->set_temp("apply/astral_vision",lvl);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me,lvl:), lvl);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;

}
void remove_effect(object me,int lvl)
{
	if(!me) return;
	me->delete_temp("soul_sense");
	me->set_temp("apply/astral_vision",0);
	me->add_temp("apply/dodge",-lvl);
	tell_object(me, "你的灵识神通失效了。\n");
}
