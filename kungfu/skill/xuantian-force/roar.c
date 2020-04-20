// roar.c 威震八方

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if(environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！\n");

	if( (int)me->query("neili") < (int)me->query("max_neili") / 20)
		return notify_fail("你的内力不够。\n");
		
	if((int)me->query_skill("xuantian-force",1) < 120)
		return notify_fail("你的玄天无极神功的修为还不够，无法使出威震八方。\n");

	skill = (int)me->query_skill("force");

	me->add("neili", -(int)me->query("max_neili") / 20);
	me->receive_damage("qi", 10);

	me->start_busy(2);
	message_vision(HIY"$N深深地吸一口气，真力迸发，发出一声惊天动地的巨吼。\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me )continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 )continue;
		me->set_temp("first_kill/"+ ob[i]->query("id"),1);
		if( !ob[i]->is_killing(me->query("id"))) ob[i]->fight_ob(me);
		if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
		damage = skill * 2 - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage * 2 ,me);
			if( (int)ob[i]->query("neili") < skill * 2 )
		tell_object(ob[i],"你觉得一股荡然的内力袭来，你招架不及，忽然间神志不清了。\n");
		}
	}

	return 1;
}
