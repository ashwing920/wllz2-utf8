//hongtianza.c 夺命三斧之「轰天砸」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg,*limbs;
	int i,size,damage;
	object my_w,target_w;
	my_w = me->query_temp("weapon");
	target_w = target->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if(!me->is_fighting())
		return notify_fail("轰天砸只能在战斗中使用。\n");	
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正茫然不知所措，加紧攻击吧。\n");
		
	if( (int)me->query_skill("duanyun-fu",1) < 100)
		return notify_fail("你目前功力还使不出「轰天砸」。\n");
		
	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够。\n");

	me->add("neili", - 200);
	msg = CYN"$N突然暴吼一声：“我砸！我砸！我砸砸砸！”，手中巨斧竟然砸向$p手中兵刃！\n"NOR;
	me->start_busy(1);

	if(target->query_temp("weapon") || target->query_temp("secondary_weapon")) {
	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
	if( target_w->weight() > 2 * random(my_w->weight()) ) {
	msg += "结果$p手中的"+target_w->query("name")+"被$P的轰天砸砸个正着，再也把握不住，立即脱手飞出！\n" NOR;
	target_w->unequip();
	target_w->move(environment(target));
	target->reset_action();
	target->start_busy( (int)me->query_skill("duanyun-fu") / 20 );
}
	msg += HIC"只见$n手中的"+target_w->query("name")+"竟然被砸断作数段，并且受到$N的劲气的激荡而向$n迅速射去！\n"NOR;
	message_vision(msg,me,target);
	target_w->unequip();
	target_w->move(environment(target));
	target_w->set("name", target_w->query("name") + "的碎片");
	target_w->set("value", target_w->query("value")/10);
	target_w->set("weapon_prop", 0);
	target->reset_action();
	target->start_busy( (int)me->query_skill("duanyun-fu") / 20 );
	limbs=target->query("limbs");
	me->start_busy(1);
	msg += "结果$p呆立当场，被攻了个措手不及！\n" NOR;
	size=(int)(me->query_skill("duanyun-fu")/10);
	damage=random(size)+size;
	damage=damage+me->query_str()/3+random(me->query_temp("apply/damage"));
	for(i=0;i<=random(size);i++)
   {
	msg =HIB"“嗤”，碎片射入$p"+limbs[random(sizeof(limbs))]+"！\n"NOR;
	message_vision(msg,me,target);
	target->receive_damage("qi",damage,me);
   }
	COMBAT_D->report_status(target);
	} else {
	msg += "可是$p急忙将自己的兵刃闪开，并没有让$P的计谋得逞。\n" NOR;
	}
	return 1;
	}
	return notify_fail(target->name() + "目前是空手，你想砸什么？\n");
}

