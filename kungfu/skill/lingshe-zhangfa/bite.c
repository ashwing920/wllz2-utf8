//Cracked by Kafei
// bite 纵蛇咬人

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string type;
	object weapon,snake;
	int lv;

	lv = (int)me->query_skill("lingshe-zhangfa", 1);

	if(!target) target = offensive_target(me);
	if(!target ||!target->is_character() ||!me->is_fighting(target) )
		return notify_fail("你只能纵蛇偷袭战斗中的对手。\n");

	if(lv < 200 )
		return notify_fail("你的灵蛇杖法不够娴熟，无法在使杖攻敌之余纵蛇伤人。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| weapon->query("skill_type") != "staff")
		 return notify_fail("你必须找到一把杖，才可以纵蛇咬人。\n");

	type = weapon->query("race");

	if(!type)
		return notify_fail("你的"+weapon->name()+"上并没有蛇。\n");

	if((int)me->query_skill("training",1) < 100 )
		return notify_fail("你的驭兽术无法顺利驱使毒蛇伤人。\n");

	if((int)me->query("neili") < lv)
		return notify_fail("你的内力不够，难以在纵蛇袭击时稳控"+weapon->name()+"。\n");

	if((int)me->query("jingli") < 300)
		return notify_fail("你的精力不够，难以在纵蛇袭击时稳控"+weapon->name()+"。\n");

	if((string)me->query_skill_mapped("force") != "hamagong")
		return notify_fail("你所用的内功与「灵蛇杖法」气路相悖！\n");

	if(target->is_busy())
		return notify_fail(target->name()+"已经动弹不得，赶紧放胆攻击吧！\n");

	snake = find_object(type);
	if(!snake) snake = load_object(type);
	message_vision(HIC"$N将"+weapon->name()+HIC"一抖，杖上金环当啷啷一阵乱响，一条"+ snake->name() +"从杖底直盘上来。\n"NOR,me);
	message_vision(HIC+ snake->name()+"猛然“嗖”的一声，向$N扑了过去。\n"NOR,target);

	if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3){
		message_vision(HIR"$N闪躲不及，被"+ snake->name() +"紧紧缠住，动弹不得。\n"NOR,target);
		target->start_busy(lv / 60);
		me->start_busy(2);
	}else {
		message_vision(HIW"谁知$N早有防备，纵身跳开一边，躲开了"+ snake->name() +"的血盆大口。\n"NOR,target);
		me->start_busy(4);
	}
	me->add("neili", -(lv/2 +50));
	me->add("jingli", -200);
	return 1;
}
