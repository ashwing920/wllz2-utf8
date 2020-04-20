// jy_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	}
	else {
		tell_object(me, HIR"忽然一阵撕心的绞痛，你中的九阴白骨爪毒性发作了。\n" NOR );
		message("vision", me->name() + "的身子突然晃了两晃，豆大的汗珠直冒出来。\n",environment(me), me);
	}
		me->receive_wound("qi",duration / 4);
		me->receive_wound("jing",duration / 10);
		me->apply_condition("jy_poison", duration - 1);
	me->set_temp("die_for","九阴白骨爪毒发死于非命！！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
