// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("qi", 20);
	me->receive_damage("qi", 10);
	me->apply_condition("rose_poison", duration - 1);
	tell_object(me, HIG "你中的" HIR "火玫瑰毒" HIG "发作了！\n" NOR );
	me->set_temp("die_for","中火玫瑰之毒而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return 1;
}
