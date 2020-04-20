// qudu.c

#include <ansi.h>

int exert(object me, object target)
{
	int con,skill;
	skill = (int)me->query_skill("hamagong",1);

	if(!target) target = me;
	if( me->is_fighting() )
		return notify_fail("战斗中运功驱毒？找死吗？\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if((int)me->query_skill("hamagong", 1) < 50)
		return notify_fail("你的蛤蟆功修为还不够。\n");

	if(!target->query_condition("snake_poison")
	&& !target->query_condition("scorpion_poison")
	&& !target->query_condition("xx_poison")
	&& !target->query_condition("chanchu_poison"))
		return notify_fail(target==me?"你":target->name()+"好像没有中毒啊！\n");
		
	me->add("neili", -200);
	me->set("jiali", 0);
	if(!me->is_busy()) me->start_busy(4);	

	if( target == me) {
		message_vision(HIG"$N盘腿坐下，将真气运至丹田，开始为自己运功逼毒。\n"NOR,target);
		message_vision(HIW"过了一阵，$N的脸上逐渐恢复了红光，精神也得到了恢复。\n"NOR,target);
	}
	else {
		message_vision(HIG"$N盘腿坐下，运起蛤蟆功，将手掌向$n的背心贴去，为$n驱除体内毒性....\n"NOR,me,target);
	}

	if(con = target->query_condition("snake_poison")){
		if (con > (skill / 3)){
			target->apply_condition("snake_poison", con - (skill / 3));
			tell_object(target,"你体内的蛇毒好像已经清除了许多。\n");
		}
		else
		{
			target->apply_condition("snake_poison", 0);
			tell_object(target,"你体内的蛇毒已经驱除干净了。\n");
		}
		message("vision", HIY+target->name()+"吐出一口金灿灿的瘀血，一滴滴黑血从伤口慢慢渗出。\n" NOR,
		environment(target), target);
		return 1;
	}
	else if (con = target->query_condition("scorpion_poison")){
		if (con > (skill / 3)){
			target->apply_condition("scorpion_poison", con - (skill / 3));
			tell_object(target,"你体内的蝎毒好像已经清除了许多。\n" NOR);
		}
		else{
			target->apply_condition("scorpion_poison", 0);
			tell_object(target,"你体内的蝎毒已经驱除干净了。\n");
		}
		message("vision", HIY+target->name()+"吐出一口金灿灿的瘀血，一滴滴青紫血珠从伤口慢慢渗出。\n" NOR,
		environment(target), target);
		return 1;
	}
	else if (con = target->query_condition("xx_poison")){
		if ((int)me->query_skill("hamagong", 1) < 30)
			return notify_fail("你的蛤蟆功修为还不够。\n");
		if (con > (skill / 3)){
			target->apply_condition("xx_poison", con - (skill / 3));
			tell_object(target,"你体内的星宿掌毒已经清除了许多。\n");
		}
		else{
			target->apply_condition("xx_poison", 0);
			tell_object(target,"你体内的星宿掌毒已经驱除干净了。\n");
		}
		message("vision",HIY+target->name()+"吐出一口紫血，苍白的脸上多了点血色。\n" NOR,
		environment(target),target);
		return 1;
	}
	else if (con = target->query_condition("chanchu_poison")){
		if ((int)me->query_skill("hamagong",1) < 40)
			return notify_fail("你的蛤蟆功修为还不够。\n");
		if (con > (skill / 3)){
			target->apply_condition("chanchu_poison", con - (skill / 3));
			tell_object(target,"你体内的蟾蜍之毒已经清除了许多。\n");
		}
		else{
			target->apply_condition("chanchu_poison", 0);
			tell_object(target,"你体内的蟾蜍之毒已经驱除干净了。\n");
		}
		message("vision",HIY+target->name()+"吐出一口青紫的淤血，苍白的脸上多了点血色。\n" NOR,
		environment(target), target);
		return 1;
	}
	return 1;
}
