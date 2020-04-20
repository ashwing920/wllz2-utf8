//ice_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) {
		message("vision", me->name() + "浑身颤抖，痛苦地哼了一声。\n", environment(me), me);
	}
	else {
		tell_object(me, HIB "忽然一阵奇寒从丹田升起，沁入四肢百骸，你中的寒冰绵掌发作了！\n" NOR );
		message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",environment(me), me);
	}

	me->receive_wound("qi",duration / 4);
	me->receive_wound("jing",duration / 10);
	me->apply_condition("ice_poison", duration - 1);
	me->set_temp("die_for","寒冰绵掌毒发攻心，死于非命！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
