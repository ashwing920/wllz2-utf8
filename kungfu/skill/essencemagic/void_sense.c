// void_sense.c - 空识神通

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
	object where = environment(me);
	int lvl,busy_time;
	lvl = me->query_skill("essencemagic",1);
	
	if( target )
		return notify_fail("空识神通只能对自己使用。\n");

	if( lvl < 150)
		return notify_fail("你的八识神通火候不足，无法使用空识神通。\n");

	if( me->is_fighting())
		return notify_fail("战斗中不能使用空识神通。\n");

	if( me->query("jingli") < lvl / 2)
		return notify_fail("你的灵力不够！\n");

	if( me->query("jing") <= lvl / 2)
		return notify_fail("你的精不够！\n");

	if( where->query("no_sleep_room") || !where->query("sleep_room"))
		return notify_fail("这里太纷乱，你无法陷入沉寂中。\n");

	if( me->query("eff_jing")<50)
		return notify_fail("你受伤太重，无法陷入沉寂当中。\n");

	if(me->query_temp("void_sense",1))
		return notify_fail("你已经在沉寂中了。\n");

	me->add("jingli", - lvl / 2);
	me->receive_damage("jing",lvl / 2);
	message_vision(HIY "$N盘膝而座，开始运用空识神通静思入定 ...\n" NOR, me);
	me->disable_player("<沉寂中>");
	me->set_temp("block_msg/all",1);
	me->set_temp("void_sense",1);
	busy_time = (lvl / 10) + random(30);
	me->start_busy(busy_time);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:),busy_time);
	return 1;
}
void remove_effect(object me)
{
	int lvl,exp,pot,intpot;

	if(!me) return;

	me->start_busy(1);
	lvl = (int)me->query_skill("essencemagic",1);
	intpot = (int)me->query_int() / 2;
	pot = intpot + (lvl / 10);
	exp = pot / 2 + random(20);
	me->receive_damage("jing",lvl / 5);
	me->receive_would("jing",lvl / 10);
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->delete_temp("block_msg/all");
	me->delete_temp("void_sense");
	me->enable_player();
	message_vision(HIW"$N沉思了许久，从沉寂中觉醒了过来。\n"NOR,me);
	return;
}
