// ss_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
		message("vision", me->name() + "凄惨地哼了一声。\n", environment(me), me);
	}
	else {
		tell_object(me, HIB "忽然一股寒流夹着一阵灼热涌上心来，你中的生死符发作了！\n" NOR );
		message("vision", me->name() + "突然倒在地上，双手在身上一阵乱抓。\n",
		environment(me), me);
	}

	me->receive_wound("qi",duration / 6);
	me->receive_wound("jing",duration / 10);
	me->apply_condition("ss_poison", duration - 1);
	me->set_temp("die_for","生死符发作，死于非命！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
