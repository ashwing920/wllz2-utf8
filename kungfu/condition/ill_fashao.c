// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
		message("vision",HIR + me->name() + "的脸蛋烧得通红，看来是发高烧了。\n"NOR, environment(me), me);
	}
	else {
		tell_object(me, HIR"你的脸蛋烧得通红，看来是发高烧了。\n" NOR );
		message("vision",RED + me->name() + "的脸蛋烧得通红，看来是发高烧了。\n"NOR,environment(me), me);
	}
	me->receive_wound("qi",10);
	me->receive_damage("qi",20);
	me->apply_condition("ill_fashao", duration - 1);
	me->set_temp("die_for","病入膏肓，终告不治死了！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
