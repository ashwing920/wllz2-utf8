#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

	tell_object(me, HIB "突然你感觉四肢麻麻的似乎不大灵便！\n" NOR );
	tell_room(environment(me), HIB + me->name()+"突然全身一颤，两张手掌心已全成黑色，黑气更顺着手臂向上攀升！\n" NOR,({ me }));

	me->receive_damage("qi",duration / 4);
	me->receive_wound("jing",duration / 10);
	if(!me->is_busy()) me->start_busy(2);
	me->set_temp("die_for", "中冰魄银针毒而死！");
	me->apply_condition("bing_poison", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
