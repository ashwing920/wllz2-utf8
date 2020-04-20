// wenrou.c 屠龙式

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg,skill_name;
	int i,lvl,attack_time;

	lvl = (int)me->query_skill("tulong-daofa",1);
	if( lvl <= 150) attack_time = 4;
	if( lvl <= 250 && lvl > 150 ) attack_time = 6;
	if( lvl <= 350 && lvl > 250 ) attack_time = 8;
	if( lvl > 350 ) attack_time = 12;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「屠龙式」字诀只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("手中无刀，你无法运用屠龙式！\n");

	if((int)me->query_skill("jiuyang-shengong",1) < 200
	&& (int)me->query_skill("shenghuo-shengong",1) < 200)
		return notify_fail("你的心法修为不够，无法使用屠龙式。\n");

	if( me->query_skill_mapped("blade") != "tulong-daofa")
		return notify_fail("你所采用的刀法并不是屠龙刀法。\n");

	if((int)me->query_skill("blade",1) < 150 )
		return notify_fail("你的基本刀法还没到家，更别说使用屠龙式了。\n");

	if((int)me->query_skill("tulong-daofa",1) < 150 )
		  return notify_fail("你的屠龙刀法还不到家，无法使用屠龙式！\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，无法使用屠龙式。\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的内力不够！\n");

	me->clean_up_enemy();
	skill_name = to_chinese((string)me->query_skill_mapped("force"));

	msg = HIW "$N运起"+ skill_name +"，手中"+ weapon->name()+ HIW"顷刻间泛起一片刀光，那正是屠龙刀法中最后一式「屠龙式」！\n" NOR;
	message_vision(msg, me);

	if((string)weapon->query("id") == "tulong dao" && attack_time > 8) attack_time = 8;
	if( random((int)me->query("combat_exp")) > target->query("combat_exp") / 4 ) {
		msg = HIR"$n正待看个清楚，却早已被$N的"+ weapon->name() +HIR"砍中！\n"NOR;
		message_vision(msg, me,target);
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
	}else break;
		me->add("neili", -300);
		me->start_busy(3);
	}
		else {
		skill_name = to_chinese((string)target->query_skill_mapped("dodge"));
		msg = HIG"$n早已看穿了$N的攻势，连忙运用"+ skill_name +"，轻身闪开一边！\n"NOR;
		message_vision(msg, me,target);
		me->start_busy(5);
		me->add("neili", -500);
	}
	return 1;
}
