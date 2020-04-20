// jue.c 「金针渡劫」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,level,damage,lvl;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("金针渡劫只能在战斗中使用。\n");

	if((int)me->query_skill("xunlei-sword", 1) < 200 )
		return notify_fail("你的迅雷剑修为还不够，还未领悟「金针渡劫」！\n");

	if( me->query_skill("xuantian-force", 1) < 200 )
		return notify_fail("你的内功修为火候未到，施展「金针渡劫」只会伤及自身！\n");

	if( !objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能运用「金针渡劫」？！\n");

	if((string)me->query_skill_mapped("force") != "xuantian-force" )
		return notify_fail("你所用的内功与「金针渡劫」心法相悖！\n");

	level = (int)me->query_skill("xunlei-sword") / 100;

	if((int)me->query("max_neili") <= level*500 )
		return notify_fail("你的内力修为不足，劲力不足以施展「金针渡劫」！\n");

	if((int)me->query("neili") <= level*80 )
		return notify_fail("你的内力不够，劲力不足以施展「金针渡劫」！\n");

	if((int)me->query_skill("xunlei-sword",1) > 500) lvl = 12;
	else if((int)me->query_skill("xunlei-sword",1) > 400) lvl = 8;
	else if((int)me->query_skill("xunlei-sword",1) > 300) lvl = 6;
	else lvl = 4;

	me->clean_enemy();
	damage = ((int)me->query_skill("dodge") + (int)me->query_skill("sword")) / 2;
	message_vision(HIY"只见$N手中"+ weapon->name()+ HIY"灵光暴长，剑法迅捷无伦，刹那间向$n攻了过去，尽是致命的凌厉毒著！！\n"NOR, me,target);
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", level);
	me->add_temp("apply/armor",-damage);
	for( i=0; i < lvl; i++ )
	if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}else break;
	me->add_temp("apply/damage", -damage);
	me->add_temp("apply/attack", -level);
	me->add_temp("apply/armor",damage);
	me->add("neili", -level*70);
	me->start_busy(3+random(3));
	return 1;
}
