// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
		message("vision", me->name() + "的捂着肚子，眉头一阵紧锁。\n", environment(me), me);
	}
	else {
		tell_object(me,YEL"你只觉得肚子一阵翻腾，又跟随着一阵绞痛。\n" NOR );
		message("vision", me->name() + "的捂着肚子，眉头一阵紧锁。\n",
		environment(me), me);
	}
	me->receive_damage("qi",10);
	me->apply_condition("ill_duzitong", duration - 1);
	me->set_temp("die_for","消化不良而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
