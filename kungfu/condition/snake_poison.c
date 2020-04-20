// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("jing",duration / 10);
	me->receive_damage("qi",duration / 4);
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG"你中的蛇毒发作了！\n" NOR );
	me->set_temp("die_for","蛇毒攻心而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return 1;
}
