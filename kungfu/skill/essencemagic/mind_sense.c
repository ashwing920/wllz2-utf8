// mind_sense.c

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
	int lvl;
	lvl = (int)me->query_skill("essencemagic", 1);

	if( !target ) target = me;

	if( lvl < 120)
		return notify_fail("你的八识神通还不够娴熟，不能使用冥识神通。\n");

	if( (int)me->query("jingli") < lvl )
		return notify_fail("你的灵力不够！\n");
		
	if(me->is_fighting())
		return notify_fail("战斗中不能使用冥识神通。\n");

	if((int)me->query("jing") < lvl)
		return notify_fail("你的精神不足，无法使用冥识神通。\n");

	me->add("jingli",-lvl);
	target->receive_curing("jing",lvl);
	target->receive_curing("qi",lvl);
	me->start_busy(4);
	if(me != target)
		message_vision( HIY "$N闭目凝神，印堂发出一道金芒罩住$n的全身...\n" NOR, me, target);
	else
		message_vision( HIY "$N闭目凝神，印堂发出一道金芒罩住$N的全身...\n" NOR, me);

	return 1;
}
