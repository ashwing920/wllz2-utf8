// roar.c 碧海潮声

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob,xiao;
	int i, skill, damage;


	if(!objectp(xiao = present("yuxiao",me)))
		return notify_fail("你手中无萧，如何吹奏碧海潮声？\n");

	if((int)me->query_skill("music",1) < 140)
		return notify_fail("你连五音十二律都没学好，更不用说吹奏碧海潮声了。\n");

	if((int)me->query_skill("bibo-shengong",1) < 140)
		return notify_fail("你的碧波神功的修为还不够，用箫吹奏碧海潮声。\n");

	if((int)me->query("jing") < 200 || (int)me->query("qi") < 200)
		return notify_fail("你现在精神不好，吹奏碧海潮声恐怕会音律大乱。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你的内力不足，无法吹奏碧海潮声。\n");

	skill = (int)me->query_skill("force") * 3;

	me->add("neili",-300);
	me->receive_damage("qi",150);
	me->receive_damage("jing",150);
	
	if(!me->is_busy()) me->start_busy(4);
	
	message_vision(HIY"$N将箫凑到嘴边，双手轻按箫末，开始吹奏起「碧海潮声」来，曲调柔和，悠悠扬扬。\n"NOR, me);
	
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || !ob[i]->is_character() || ob[i] == me) continue;
		if(me->is_fighting(ob[i]) || ob[i]->is_fighting(me)) continue;
		tell_object(ob[i],HIC"\n一阵和暖清爽的微风向你拂面而来，你顿觉精神振奋 . . . .\n"NOR);
		ob[i]->receive_heal("qi",skill);
		ob[i]->receive_heal("jing",skill);
		if((int)me->query_skill("music",1) < 800) 
		me->improve_skill("music",skill /3);
	}
	return 1;
}
