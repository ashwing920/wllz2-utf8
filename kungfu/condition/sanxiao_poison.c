// sanxiao_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("qi",duration / 6);
	me->receive_damage("qi",duration / 4);
	me->apply_condition("sanxiao_poison", duration - 1);
	message_vision(HIG"$N脸上忽然露出诡异的一笑，看来是"HIB"三笑逍遥散"HIG"发作了！\n" NOR, me);
	me->set_temp("die_for","三笑逍遥散之毒发而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return 1;
}
