// zhua_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if(!living(me) ) {
		message("vision", me->name() + "痛苦地呻吟着。\n", environment(me), me);
	}
	else {
		tell_object(me, HIB "忽然一丝热流自体内升起, 缓缓的浸入你四肢百骸。原来你中的凝血神抓发作了！\n" NOR );
		message("vision", me->name() + HIR "的身子突然一阵颤抖, 牙关咬得咯咯作响。\n"+me->name()+"忽然打了一个哆嗦,脸上露出痛苦而诡异的笑容。\n" NOR,
		environment(me), me);
	}
	me->receive_wound("qi",duration / 6);
	me->receive_wound("jing",duration / 10);
	me->apply_condition("zhua_poison", duration - random(3));
	me->set_temp("die_for","中凝血神抓之毒而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
