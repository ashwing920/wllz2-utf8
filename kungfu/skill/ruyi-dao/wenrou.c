// wenrou.c 温柔一刀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int i,lvl,attack_time;

	lvl = (int)me->query_skill("ruyi-dao",1);
	if( lvl <= 150) attack_time = 4;
	if( lvl <= 250 && lvl > 150 ) attack_time = 6;
	if( lvl <= 350 && lvl > 250 ) attack_time = 8;
	if( lvl > 350 ) attack_time = 12;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「温柔一刀」字诀只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("「温柔一刀」开始时必须有刀在手！\n");

	if((int)me->query_skill("beiming-shengong",1) < 200)
		return notify_fail("你的北冥神功修为不够，无法使用温柔一刀。\n");

	if( me->query_skill_mapped("blade") != "ruyi-dao")
		return notify_fail("你必须将激发如意刀为刀法才可以使用温柔一刀。\n");

	if((int)me->query_skill("blade",1) < 150 )
		return notify_fail("你的基本刀法还没到家，无法使用温柔一刀。\n");

	if((int)me->query_skill("ruyi-dao",1) < 150 )
		  return notify_fail("你的如意刀还不到家，无法使用温柔一刀！\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，无法使用温柔一刀。\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的内力不够！\n");

	me->clean_up_enemy();
	msg = HIR "$N使出如意刀绝技"+HIM"「温柔一刀」"NOR + HIR"，刀锋寒芒四射！\n" NOR;
	message_vision(msg, me);

	if( random((int)me->query("combat_exp")) > target->query("combat_exp") / 5 ) {
		msg = HIR"$n闪躲不及，被$N的攻击狠狠的砍中了！\n"NOR;
		message_vision(msg, me,target);
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",0);
	}else break;
		me->add("neili", -200);
		me->start_busy(3);
	}
		else {
		msg = HIC"$n慌忙闪身躲避，远远的避开了$N的攻击！\n"NOR;
		message_vision(msg, me,target);
		me->add("neili",200);
		me->start_busy(5);
	}
	return 1;
}
