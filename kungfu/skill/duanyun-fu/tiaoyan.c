// tiaoyan.c 夺命三斧之「挑眼式」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if(!target) target = offensive_target(me);

	if(!target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("「挑眼式」只能在战斗中使用。\n");

	if( me->query_skill("duanyun-fu",1) < 100)
		return notify_fail("你的断云斧不够火候呢！\n");
	if( me->query("neili") < 200)
		return notify_fail("你的内力不够！\n");
	if(target->is_busy())
		return notify_fail(target->name() + "正象只无头苍蝇，快放胆攻击吧。\n");
	
	msg=HIG"$N使出夺命三斧之「挑眼式」，斧尖疾挑$n双眼。\n";

	me->start_busy(2);
	me->add("neili",- 200);
	
	if((int)random(me->query("combat_exp")) > (int)target->query("combat_exp")/3){
	
	msg += "结果$p只觉得眼前一黑，双眼一阵剧痛，接着什么也看不见了。\n" NOR;
	target->start_busy(2);
	target->set_temp("block_msg/all",1);
	target->add("qi",-((int)me->query_skill("duanyun-fu")/10));
	call_out("unblock_msg",(me->query_skill("duanyun-fu") / 10),me);
	} else {
		msg += "可是$p看破了$P的企图，并急忙躲开了。\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

void unblock_msg(object target)
{
	if(target->is_character() && target->query_temp("block_msg/all")){
		target->delete_temp("block_msg/all");
		return;
	}

}
		