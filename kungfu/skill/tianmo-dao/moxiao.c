// moxiao 魔笑击
// 99.2.1  by Bless

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,j;
	string weapon_name;

	if(!target) target = offensive_target(me);
	if(!target || !target->is_character()|| !me->is_fighting(target))
		return notify_fail("「魔笑击」只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	||(string)weapon->query("skill_type") != "blade")
		return notify_fail("你所使用的武器不对\n");

	if(me->query("family/family_name") != "日月神教")
		return notify_fail("你不是日月神教弟子，不能使用这项绝技！\n");

	if((int)me->query_int() < 35)
		return notify_fail("你的先天不足，不能领悟「魔笑七击」！�n");

	if((int)me->query_skill("tianmo-dao", 1) < 101)
		return notify_fail("你的天魔刀法不够娴熟，不会使用「魔笑击」绝技。\n");

	if((int)me->query_skill("tianmo-dafa", 1) < 101)
		return notify_fail("你的天魔大法不够深厚，不会使用「魔笑击」绝技。\n");

	if((int)me->query("neili")<500)
		return notify_fail("你现在内力太弱，不能使用「魔笑击」绝技。\n");

	if((time()-(int)me->query_temp("last_perform_time")) < me->query_temp("last_perform_busy"))
			return notify_fail("你的内力运转的没有这么快。\n");

	me->clean_up_enemy();
	weapon_name = weapon->query("name");
	me->set_temp("last_perform_time",time());
	me->set_temp("last_perform_busy",3);
	message_vision(HIR"\n只见$N阴侧侧长笑数声，天魔刀法接连出招，手中"+ weapon_name +"接连向$n砍去。\n"NOR,me,target);
	if(random(2)==1) i=7;
	else i=6;
	me->start_busy(3);
	me->add("neili",-200);
	for(j=1;j<=i;j++)
	if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		if(!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, weapon, 1);
		me->set_temp("action_flag",0);
	}else break;
	return 1;
}
