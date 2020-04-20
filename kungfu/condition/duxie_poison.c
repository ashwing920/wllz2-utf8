// duxie_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;	

	me->receive_wound("jing",duration / 3);
	me->receive_wound("qi",duration);
	me->apply_condition("duxie_poison", duration - 1);
	tell_object(me,RED"你浑身发痒，连忙用手去抓，不一会儿就抓出一道血红的抓痕。\n" NOR );
	me->set_temp("die_for","身中蝎毒，全身溃烂而死！");
	me->delete_temp("last_damage_from");
	if(!me->is_busy()) me->start_busy(1);
	return 1;
}
