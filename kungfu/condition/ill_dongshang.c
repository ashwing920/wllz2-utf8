// ill_dongshang.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
		message("vision", me->name() + "肢体僵直，看来被冻伤了。\n", environment(me), me);
	}
	else {
		tell_object(me, HIB "你觉得肢体末端一阵僵直，看来是被冻伤了！\n" NOR );
		message("vision",BLU + me->name() + "的肢体僵直青肿，看来被冻伤了。\n"NOR, environment(me), me);
	}
	me->receive_wound("qi",10);
	me->receive_damage("qi",20);
	me->apply_condition("ill_dongshang", duration - 1);
	me->set_temp("die_for","因冻伤而死于非命！");
	me->delete_temp("last_damage_from");
	return CND_CONTINUE;
}
