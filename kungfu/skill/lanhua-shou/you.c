// you.c 幽兰弄影

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int str;

	if(!target) target = offensive_target(me);
	if(!target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("你只能在战斗中使用「幽兰弄影」。\n");

	if(objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")))
		return notify_fail("你必须放下武器才可以使用「幽兰弄影」。\n");

	if((int)me->query_skill("bibo-shengong",1) < 150)
		return notify_fail("你碧波神功的功力不够，无法使用「幽兰弄影」。\n");

	if((int)me->query_skill("hand",1) < 150)
		return notify_fail("你的手法修为不够，目前还不能使用「幽兰弄影」。\n");

	if((int)me->query_skill("lanhua-shou",1) < 150)
		return notify_fail("你的兰花拂穴手修为不足，无法运用「幽兰弄影」。\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你内力现在不够, 不能使用「幽兰弄影」！\n");

	if(me->query_temp("youlan"))
		return notify_fail("你已经在运用「幽兰弄影」了。\n");

	message_vision(WHT"$N双手反手伸出，交叉拈指，将体内的真气化入手心之中。\n"NOR, me, target);
	str = me->query("str")/3*2;
	me->add_temp("apply/strength",str);
	me->add_temp("str",str);
	me->add("neili", -500);
	me->start_busy(2);
	me->set_temp("youlan",1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me,str:),me->query_skill("hand",1));
	return 1;
}
void remove_effect(object me,int str)
{
	tell_object(me,WHT"你手中的真气慢慢散去，「幽兰弄影」的效果也逐渐消失了。\n"NOR);
	me->add_temp("apply/strength",-str);
	me->add_temp("str",-str);
	me->delete_temp("youlan");
}
