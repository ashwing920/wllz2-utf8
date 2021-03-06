// hitback.c

#include <ansi.h>

void remove_effect(object me);
int exert(object me, object target)
{
	int skill, total_time;

	if( !me->is_fighting() )
		return notify_fail("斗转星移神功转力之术只能在战斗中使用。\n");
	if( target != me ) 
		return notify_fail("你只能用斗转星移神功转移对自己的攻击。\n");
	if( (int)me->query("neili") < 100 ) 
		return notify_fail("你的内力不够。\n");
	if( me->query_temp("shift") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = (int)me->query_skill("force");

	me->add("neili", -100);
	write(HIC"你心念一转，运起斗转星移神功，打算把敌人的攻击转回给他自己。\n"NOR);
	me->set_temp("shift", "hitback");
	total_time = (int)me->query_skill("douzhuanxingyi", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), total_time);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me)
{
	if(!me) return;
	if (me->query_temp("shift") == "hitback"){
		me->delete_temp("shift");
		message_vision("$N的斗转星移神功运行完毕，缓缓地将内力收回了丹田。\n", me);
	}
}
 
int clean_up()
{
	return 1;
}
void reset()
{
}
