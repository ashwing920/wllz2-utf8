// hanxing-fada/lastrisk.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int i,s;
	string msg;
	object *ob;
	object weapon;
	s = me->query_skill("hanxing-bada", 1);
	if( !target ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("孤注一掷只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你必须先有暗器。\n");
		
	if( s < 120)
		return notify_fail("你的寒星八打修为太浅。\n");
	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不足！\n");
		
	msg = CYN "$N孤注一掷，发出所有暗器攻向$n！";
	me->start_busy(2);
	me->add("neili",-200);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ){
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->receive_wound("qi", random(s)*2);
	} else {
		msg += "可是$p躲过了$P的最后一击。\n" NOR;
	}
	message_vision(msg, me, target);
	ob = all_inventory(me);	 //use out all throwing
	for(i=sizeof(ob)-1; i>=0; i--) {
	if( (string)ob[i]->query("equipped")!="wielded" ) continue;
	ob[i]->unequip();
		  ob[i]->move(environment(me));
	}
		  me->reset_action();
	return 1;
}

