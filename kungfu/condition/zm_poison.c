#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) {
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	}
	else {
		tell_object(me, HIB "忽然一阵刺骨的奇痛袭来，你中的子母飞针之毒发作了！\n" NOR );
		message("vision", me->name() + "的身子突然晃了两晃，脸上一阵扭曲，好像万分痛苦。\n",environment(me), me);
	}

	me->receive_wound("qi",duration / 6);
	me->receive_wound("jing",duration / 10);
	me->apply_condition("zm_poison", duration - 1);
	me->set_temp("die_for","中子母飞针之毒死了！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
