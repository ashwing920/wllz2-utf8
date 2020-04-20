// silent_sense.c - 寂识神通

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
	int lvl;

	lvl = (int) me->query_skill("essencemagic",1);

	if( target )
		return notify_fail("寂识神通只能对自己使用。\n");

	if( me->is_fighting())
		return notify_fail("战斗中不能使用寂识神通。\n");

	if((int)me->query("max_jingli") < 1000 )
		return notify_fail("你的精力修为不够，无法使用寂识神通！\n");

	if( lvl < 200)
		return notify_fail("你的八识神通还不够娴熟，无法使用寂识神通。\n");

	if((int)me->query("jing") < 100 )
		return notify_fail("你的精不够！\n");

	if((int)me->query("jingli") <= 50)
		return notify_fail("你的精力不够了。\n");

	me->add("jingli", -50);
	me->receive_damage("jing", 50);

	message_vision(HIY "$N盘膝而座，开始运用寂识神通静思入定 ...\n" NOR, me);

	if( random((int)me->query_skill("magic")) > (int)me->query_int() * 10 ) {
		if( random((int)me->query("max_jingli")) < (int)me->query("jingli")/2 ) {
			me->set_skill("essencemagic", lvl -1 );
			write( HIR "你觉得脑中一片混乱，你的八识神通降低了！\n" NOR );
			return 1;
		}
		else if(lvl*lvl*lvl /10 > (int)me->query("combat_exp")){
			write(HIC"可能是缺乏实战经验，你总是难以理解八识神通的奥妙。\n");
			return 1;
		}
		me->set_skill("essencemagic", lvl + 1);
		write( HIG "你的八识神通提高了！\n" NOR );
		return 1;
	}
	write("可是你只觉得一无所获。\n");
	return 1;
}
