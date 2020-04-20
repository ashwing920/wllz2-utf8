// roar.c 后天霸气

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;
	if(environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！\n");

	if( ((int)me->query("neili") < 300 ) ||
		( (int)me->query_skill("xuehai-mogong",1) < 150) )
		return notify_fail("你鼓足真气“嘛”的吼了一声, 结果吓走了几只老鼠。\n");

	skill = (int)me->query_skill("force");

	me->add("neili",-300);
	me->receive_damage("qi",10);
	me->start_busy(3);
	
	ob = all_inventory(environment(me));
	
	message_vision("$N深深地吸一口气，吐出"+HIY+"般若波罗蜜"+NOR+"一声梵唱.....\n" NOR,me);
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )   continue;
		me->set_temp("first_kill/"+ ob[i]->query("id"),1);
		if( !me->is_killing(ob[i]->query("id")) ) me->kill_ob(ob[i]);
		if( !ob[i]->is_killing(me) ) ob[i]->fight_ob(me);
		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage,me);
			if( (int)ob[i]->query("neili") < skill )
				ob[i]->receive_wound("qi", damage / 3,me);
			tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！！！\n");
		}
	}

	return 1;
}

