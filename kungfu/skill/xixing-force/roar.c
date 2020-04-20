// roar.c for xixin-dafa

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if(!me->is_fighting())
		return notify_fail("这种武功必须在战斗中使用。\n");
		
	if(environment(me)->query("no_fight")
	|| environment(me)->query("fight_room"))
		return notify_fail("这里禁止战斗！无法用内功伤人！\n");
	
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力不够。\n");

	if((int)me->query_skill("xixing-force",1) < 100)
		return notify_fail("你的吸星大法修为不够。\n");

	skill = me->query_skill("force");

	me->add("neili", -300);
	me->receive_damage("qi", 190);

	me->start_busy(2);
	message_vision(HIR "$N深深地吸一口气，运起吸星大法对着长空狂吼一声。\n你的耳朵里顿时嗡的一声.........\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
		me->set_temp("first_kill/"+ob[i]->query("id"),1);
		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("qi", damage,me);
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("qi", damage/2,me);
			tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n");
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me->query("id")) ) ob[i]->fight_ob(me);
	}

	return 1;
}
