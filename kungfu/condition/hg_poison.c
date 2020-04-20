#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

	if( !living(me) ) {
		message("vision", me->name() + "手脚发抖，无精打采，全身乏力。\n", environment(me), me);
	}
	else {
		tell_object(me,YEL"你只觉得全身乏力，全身内力不停外泄！\n" NOR );
		message("vision", me->name() + "“哎”的叹了口气，眼神无光，连站都站不稳。\n",environment(me), me);
	}
	me->receive_wound("qi",duration / 4 );
	me->receive_wound("jing",duration / 10);
	if((int)me->query("neili") > 50) {
		me->add("neili",- (int)me->query("max_neili") / 2);
		if((int)me->query("neili") < 0) me->set("neili",0);
	}
	me->apply_condition("hg_poison", duration - 1);
	me->set_temp("die_for","中化骨绵掌而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
