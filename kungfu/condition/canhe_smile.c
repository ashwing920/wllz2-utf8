#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if(living(me)) {
		tell_object(me,YEL"你只觉得全身瘫软，再也驻留不住一丝真气！\n" NOR );
		message("vision", me->name() + "捧住肚子，嘻嘻哈哈地直笑得两眼翻白，差点喘不过气来。\n", environment(me), me);
	}
	me->receive_damage("qi",duration / 5);
	if((int)me->query("neili") > 50) {
		me->add("neili",- (int)me->query("max_neili") / 2);
		if((int)me->query("neili") < 0) me->set("neili",0);
	}
	me->apply_condition("canhe_smile", duration - 1);
	me->set_temp("die_for","活活笑死了！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
