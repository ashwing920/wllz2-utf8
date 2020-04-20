// sanshen.c 华岳三神峰

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
 
	if(!me->is_fighting())
		return notify_fail("「华岳三神峰」只能在战斗中使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	||(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够！\n");

	if((int)me->query_skill("blade",1) < 120)
		return notify_fail("你的基本刀法还没到家呢！\n");
		
	if((int)me->query_skill("fanliangyi-dao",1) < 120)
		return notify_fail("你的「反两仪刀法」还不到家，无法使用「华岳三神峰」！\n");

	msg = HIY "$N使出华山剑派绝技「华岳三神峰」，身法突地变得异常灵动飘忽！\n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

	me->add("neili", - 200);
	me->start_busy(random(3));

	return 1;
}
