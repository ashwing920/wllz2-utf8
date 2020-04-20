// pan.c 
// 盘龙诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg,name,name1;
	object tar_weapon,my_weapon;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("盘龙诀只能对战斗中的对手使用。\n");

	if((int)me->query_skill("riyue-bian", 1) < 120 )
		return notify_fail("你的日月贬法还不够娴熟，不会使用盘龙诀。\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的内力不够！\n");

	if((int)me->query_con() < 30 )
		return notify_fail("盘龙诀需要很高的内功，才能出奇不异的把对方的兵器夺下来。\n");


	if(!objectp(my_weapon = me->query_temp("weapon"))
	|| my_weapon->query("skill_type") != "whip")
		return notify_fail("你手中无鞭，无何使用盘龙诀？\n");

	if(!objectp(tar_weapon = target->query_temp("weapon")))
		return notify_fail("对方没有使用武器。\n");     

	me->clean_up_enemy();
	name = tar_weapon->name();
	name1 = my_weapon->name();

	msg = HIW"$N手举"+ name1 + HIW"，运用日月鞭中的绝技「盘龙式」，手中"+ name1 + HIW"“唰”的声向$n飞去！\n"NOR;
	if(( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4)
	&& (me->query("neili") > random(target->query("neili")))) {
		msg += HIY"\n结果$p的"+ name + HIY"被$P的"+ name1 +HIY"紧紧盘住，$p的"+ name +HIY"脱手飞出！\n" NOR;
		if(tar_weapon->query("ownmake")) {
			tar_weapon->unequip();
		} else {
			tar_weapon->unequip();
			tar_weapon->move(me);
		}
		me->add("neili", -200);
		me->start_busy(1);
		target->start_busy(2);
		target->reset_action();
	} 
	else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(3);
		me->add("neili", -100);
	}
	message_vision(msg, me, target);
	return 1;
}
