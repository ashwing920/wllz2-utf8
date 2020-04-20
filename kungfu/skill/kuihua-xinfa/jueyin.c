// fanchang.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	object *ob;
	int skill,damage,i;

	if(environment(me)->query("no_fight")
	|| environment(me)->query("fight_room"))
		return notify_fail("你不能在禁止战斗的地方使用内功的这个功能！\n");

	if( !me->is_fighting())
		return notify_fail("天籁绝音只能在战斗中使用。\n");

	if((int)me->query_skill("kuihua-xinfa",1) < 120 )
		return notify_fail("你的葵花心法功力不够，不能使用天籁绝音攻击对方！\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够，不能使用天籁绝音。\n");

	message_vision(HIM"$N丝线盘指，犹如琴状，右手轻拨，丝线顷刻发出阵阵绝妙的音律！\n\n" NOR, me);

	skill = (int)me->query_skill("kuihua-xinfa");

	me->clean_up_enemy();
	me->start_busy(4);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;
		damage = me->query_skill("force") + me->query_skill("kuihua-xinfa",1)/2;
		if( damage > 0 ) {
			ob[i]->receive_wound("qi", damage / 2,me);
			ob[i]->receive_damage("qi", damage,me);
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_damage("jing", damage/2,me);
				tell_object(ob[i], HIM"你忽然觉得仙乐飘起，无数美貌的仙女在你跟前飘荡，抚弄着你的脸颊......\n" NOR);
				message_vision(HIM"\n只见$N面带微笑，眼神中是那么幸福，那么满足......\n\n"NOR,ob[i]);
		}
		me->set_temp("first_kill/"+ ob[i]->query("id"),1);
		if( userp(ob[i]) ) me->kill_ob(ob[i]);
		else if( !ob[i]->is_killing(me->query("id")) ) me->kill_ob(ob[i]);
	}
	return 1;
}
