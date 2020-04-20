//xuanming_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) {
		message("vision", me->name() + "浑身颤抖，痛苦地哼了一声。\n", environment(me), me);
	}
	else {
		tell_object(me, HIG"忽然一阵奇寒幽幽的从胸口贯穿到你的后背，再渐渐的沁入四肢百骸，你不禁打了个冷颤！\n" NOR );
		message("vision", HIG + me->name() + "的脸色一阵青一阵白，牙关格格地响了起来。\n"NOR,environment(me), me);
	}

	me->receive_wound("qi",duration / 2);
	me->receive_wound("jing",duration / 6);
	me->apply_condition("xuanming_poison", duration - 1);
	me->set_temp("die_for","玄冥之毒发作，毒发攻心而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
