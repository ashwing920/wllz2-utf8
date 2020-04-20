// 万佛朝宗

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
						
	int damage, jiali, attack, defense;
	object weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target || !me->is_fighting(target) || !living(target) )
		return notify_fail("「万佛朝宗」只能在战斗中对对手使用。\n");          
	
	if( (int)me->query_skill("banruo-zhang",1) < 150 )
		return notify_fail("你的般若掌不够娴熟，不会使用「万佛朝宗」！\n");
	
	if( (int)me->query_skill("strike",1) < 150 )
		return notify_fail("你的基本手法不够娴熟，不会使用「万佛朝宗」！\n");

	if( (int)me->query_skill("yijinjing",1) < 120 )
		return notify_fail("你的易筋经神功等级不够，不能使用「万佛朝宗」！\n");  
	
	if( (int)me->query_str() < 35 )
		return notify_fail("你的臂力不够强，不能使用「万佛朝宗」！\n");
	
	if( (int)me->query("max_neili") < 1200 )
		return notify_fail("你的内力修为不够，不能使用「万佛朝宗」！\n");
	
	if( (int)me->query("neili") < 800 )
		return notify_fail("你的内力太少了，无法使用出「万佛朝宗」！\n");   
	
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你不能使用武器！\n");
	
	jiali = (int)me->query("jiali")+1;
	attack = (int)me->query("combat_exp")/1000;
	attack += (int)me->query_skill("strike",1);
	attack += (int)me->query("neili")/5;
	defense = (int)target->query("combat_exp")/1000;
	defense += (int)target->query_skill("dodge",1);
	defense += (int)target->query("neili")/7;
	attack = (attack+random(attack+1))/2;
	
	damage = (int)me->query_skill("banruo-zhang",1)/20 * jiali;
	
	message_vision(HIR"\n$N突然双臂骨节一阵爆响，两手犹如如来佛掌，带着排山倒海般的内劲向$n挥去，好一式佛门「万佛朝宗」！\n"NOR,me,target);
	if( attack > defense ) { 
		message_vision(HIY"只听一声闷哼，$n的胸口正中$N一掌，一口鲜血从$n口中喷了出来，已受极重内伤。\n"NOR,me, target);
		tell_object(target, RED"你只觉得霍的胸口骨骼一阵剧痛，看来受伤不清！\n"NOR);
		target->receive_damage("qi", damage,me); 
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -jiali);
	}
	else
	{
		message_vision(HIW"$n见机，赶忙跃出数丈，侥幸的跺过了$N的这一招\n"NOR,me, target);
	}
	me->add("neili", -200);
	me->start_busy(2);
	return 1;
}
