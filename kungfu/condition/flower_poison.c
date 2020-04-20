// flower_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("jing", 20);
	me->receive_damage("qi", 10);
	me->apply_condition("flower_poison", duration - random(5));
	tell_object(me, HIG "你中的" HIR "断肠花毒" HIG "发作了！\n" NOR );
	me->set_temp("die_for","中断肠花毒而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return 1;
}
