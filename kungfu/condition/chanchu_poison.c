// chanchu_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) {
		message("vision", me->name() + "“哇”的吐出一口黑紫色的淤血，散发出一股难闻的恶臭。\n", environment(me), me);
	}
	else {
		tell_object(me,HIB"忽然一股撕心裂肺的痛楚涌上心头，你体内的蟾蜍之毒的发作了！\n" NOR );
		message("vision",HIG + me->name() + "浑身虚汗淋漓，脸色骤时变得铁青，嘴角缓缓的渗出一丝黑紫色的淤血。\n"NOR,
		environment(me), me);
	}

	me->receive_wound("qi",duration / 4);
	me->receive_wound("jing",duration / 10);
	me->apply_condition("chanchu_poison", duration - 1);
	me->set_temp("die_for","体内的蟾蜍之毒毒性攻心，不治而死了！");
	me->delete_temp("last_damage_from");

	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}
