// jianzhang.c  剑掌五连环

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i;
 
	if( !target ) target = offensive_target(me);
	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target))
		return notify_fail("「剑掌五连环」只能在战斗中使用。\n"); 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「剑掌五连环」开始时必须拿着一把剑！\n");
	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够！\n");
	if( (int)me->query_skill("zixia-shengong",1) < 120)
		return notify_fail("你的紫霞神功不够！\n");
	if( (int)me->query_skill("sword",1) < 100 )
		return notify_fail("你的基本剑法还不到家，无法使用剑掌五连环！\n");

	msg = HIY "$N使出华山剑派绝技「剑掌五连环」，身法陡然加快！\n" NOR;
	message_vision(msg, me);
	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
	msg = CYN"结果$p被$P攻了个措手不及！\n" NOR;
	message_vision(msg, me, target);

	for(i = 0; i < 5; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",0);
	}else break;
	me->add("neili",-200);
	me->start_busy(random(3)+2);
	}
		else {
		msg = "$p轻身闪开，躲避了$P凶猛的招式。\n" NOR;
		message_vision(msg, me,target);
		me->start_busy(5);
	}

	return 1;
}
