// roar.c 佛门狮子吼

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if( (int)me->query("neili") < 200)
		return notify_fail("你的内力不够。\n");

	if(environment(me)->query("no_fight"))
		return notify_fail("这里不能使用这种外功！\n");

	if((int)me->query_skill("yijinjing",1) < 120)
		return notify_fail("你的易筋经神功修为不够，无法使出佛门狮子吼！\n");

	skill = (int)me->query_skill("force");
	me->add("neili",-200);
	me->receive_damage("qi",50);
	me->start_busy(5);
       
	message_vision(HIY "$N深深地吸一囗气，真力迸发，运起佛门狮子吼，发出一声惊天动地的巨吼！！\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++){
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		me->set_temp("first_kill/"+ ob[i]->query("id"),1);
		if(!ob[i]->is_killing(me->query("id")) ) ob[i]->fight_ob(me);
		if( damage > 0 ){
			ob[i]->receive_damage("jing", damage,me);
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_damage("jing", damage,me);
			tell_object(ob[i],HIR"你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n"NOR);
		}
	}
	return 1;
}
