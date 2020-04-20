// heart_sense.c - 心识神通

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
	int lvl = (int)me->query_skill("essencemagic",1);

	if( lvl < 120)
		return notify_fail("你的八识神通还不够娴熟，无法使用心识神通。\n");

	if( !target || !target->is_character() )
		return notify_fail("你要对谁使用心识神通？\n");
	
	if( me->is_fighting())
		return notify_fail("战斗中不能使用心识神通！\n");

	if( target->is_corpse())
		return notify_fail("你想把"+ target->name(1)+"救醒，可惜已经太晚了。\n");

	if( (int)me->query("jingli") < 100 )
		return notify_fail("你的精力不够！\n");

	if( me->query("jing") <= 50 )
		return notify_fail("你的精神不够！\n");

	me->add("jingli",-100);
	me->receive_damage("jing",50);

	message_vision( HIY "$N一手放在$n的天灵盖上, 一手贴在$n的后心, 闭上眼睛缓缓低吟...\n" NOR, me, target);
	if( random(me->query("max_jingli")) > 300 )
		target->revive();
	else
		me->unconcious();

	if( me->is_fighting()) me->start_busy(3);
	return 1;
}
