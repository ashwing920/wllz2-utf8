// roar.c 佛门狮子吼

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if(environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！\n");

	if(me->query("family/family_name") != "少林派" 
	&& me->query("family/family_name") != "明教" )
		return notify_fail("只有少林弟子或明教弟子才可以使用佛门狮子吼。\n");

	if( ((int)me->query("neili") < (int)me->query("max_neili")/ 20 ) 
	|| ((int)me->query_skill("jiuyang-shengong",1) < 120) )
		return notify_fail("你鼓足真气“喵”的吼了一声, 结果吓走了几只老鼠。\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为还不够，不能使用佛门狮子吼。\n");

	skill = (int)me->query_skill("force");

	me->add("neili", - (int)me->query("max_neili")/ 20);
	me->receive_damage("qi", 10);

	me->start_busy(5);
	message_vision(HIY "$N深深地吸一囗气，真力迸发，发出一声惊天动地的巨吼！！\n" NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
		damage = skill * 3 - ((int)ob[i]->query("max_neili") / 10);
		me->set_temp("first_kill/"+ ob[i]->query("id"),1);
		if(!ob[i]->is_killing(me->query("id"))) ob[i]->fight_ob(me);
		if( damage > 0 ){
			ob[i]->receive_damage("jing", damage,me);
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_damage("jing", damage,me);
			tell_object(ob[i],HIR"你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！！！\n"NOR);
		}
	}
	return 1;
}
