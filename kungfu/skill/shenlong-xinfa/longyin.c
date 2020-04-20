// longyin.c 龙吟大法

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if(environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗！无法用内功伤人！\n");

	if(me->query("family/family_name") != "神龙教" )
		return notify_fail("只有神龙教弟子才可以使用龙吟大法。\n");

	if((int)me->query_skill("shenlong-xinfa",1) < 150)
		return notify_fail("你的神龙心法还不够娴熟，无法使用龙吟大法伤人。\n");

	if((int)me->query("neili") < (int)me->query("max_neili") / 20 )
		return notify_fail("你的内力不够，无法使用龙吟大法伤人。\n");

	if(me->query("max_neili") < 1000)
		return notify_fail("你的内力修为还不够，不能使用龙吟大法。\n");

	me->clean_up_enemy();
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
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage,me);
			if( (int)ob[i]->query("neili") < skill * 2 )
			ob[i]->receive_damage("jing", damage,me);
			tell_object(ob[i],HIY"你眼前忽然出现数条金龙夹带着一股强劲的内力向你袭来，你只觉得脑袋似乎就要迸裂。\n");
			me->set_temp("first_kill/"+ob[i]->query("id"),1);
			if( !ob[i]->is_killing(me->query("id")) ) ob[i]->fight_ob(me);
			me->fight_ob(ob[i]);
		}
	}
	return 1;
}
