// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	int skill,level;

	if(!target) target = me;
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if((int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	skill = (int)me->query_skill("jiuyang-shengong",1);

	if(skill < 150)
		return notify_fail("你的九阳神功还不够娴熟，无法运用九阳真气。\n");

	if(me->query_temp("weapon"))
		return notify_fail("你必须空手才可以运用九阳真气进行驱毒。\n");

	if((int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if(!target->query_condition("ice_poison") && !target->query_condition("jy_poison")
	&& !target->query_condition("xuanming_poison") && !target->query_condition("qishang_poison"))
			return notify_fail((target == me ?"你":"对方") + "并没有中毒。\n");

	if( target == me) {
		message_vision(HIW"$N盘腿坐下，将真气运至丹田，开始为自己运功逼毒。\n"NOR,me);
		message_vision(HIW"过了一阵，$N的脸上逐渐恢复了红光，精神也得到了恢复。\n"NOR,me);
	}
	else {
		message_vision(HIW"$N盘腿坐下，运起九阳神功，将手掌向$n的背心贴去，缓缓地将九阳真气输入到$n体内....\n"
		"过了一会，$N额头上冒出豆大的汗珠，$n回了一口气，吐出了一口淤血，脸色渐渐泛起了红光。\n" NOR,me, target);
	}

	me->add("neili", -150);
	me->set("jiali",0);
	me->start_busy(5);
	target->start_busy(5);
	if(level = target->query_condition("ice_poison")){
		if( level > skill / 3){
			target->apply_condition("ice_poison",level - (skill / 3));
			tell_object(target,"你体内的寒冰真气已经消散了许多。\n");
		}
		else{
			target->apply_condition("ice_poison",0);
			tell_object(target,HIW"你体内的寒冰真气已经被九阳真气驱除了。\n"NOR);
		}
		return 1;
	}
	else if(level = target->query_condition("xuanming_poison")){
		if( level > skill / 3){
			target->apply_condition("xuanming_poison",level - (skill / 3));
			tell_object(target,"你体内的玄冥之毒已经消散了许多。\n");
		}
		else {
			target->apply_condition("xuanming_poison",0);
			tell_object(target,HIW"你体内的玄冥之毒已经被九阳真气驱除了。\n"NOR);
		}
		return 1;
	}
	else if(level = target->query_condition("jy_poison")){
		if(level > skill / 3){
			target->apply_condition("jy_poison",level - (skill / 3));
			tell_object(target,"你体内的九阴之毒已经消散了许多。\n");
		}
		else {
			target->apply_condition("jy_poison",0);
			tell_object(target,HIW"你体内的九阴之毒已经被九阳真气驱除了。\n"NOR);
		}
		return 1;
	}
	else if(level = target->query_condition("qishang_poison")){
		if(level > skill / 3){
			target->apply_condition("qishang_poison",level - (skill / 3));
			tell_object(target,"你体内的暗伤已经退了许多。\n");
		}
		else {
			target->apply_condition("qishang_poison",0);
			tell_object(target,HIW"九阳真气已经驱除了你体内的暗伤。\n"NOR);
		}
		return 1;
	}
}
