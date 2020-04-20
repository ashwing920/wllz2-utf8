// jianying.c 剑影

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg,skill_name;
	int i,lvl,attack_time;

	lvl = (int)me->query_skill("murong-sword",1);
	if( lvl <= 150) attack_time = 4;
	if( lvl <= 250 && lvl > 150 ) attack_time = 6;
	if( lvl <= 350 && lvl > 250 ) attack_time = 8;
	if( lvl > 350 ) attack_time = 12;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「剑影」只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你手中无剑，何来剑影！\n");

	if((int)me->query_skill("shenyuan-gong",1) < 200
	&& (int)me->query_skill("douzhuanxingyi",1) < 200)
		return notify_fail("你的心法修为不够，无法使用剑影。\n");

	if( me->query_skill_mapped("blade") != "murong-daofa")
		return notify_fail("你必须运用慕容刀法和慕容剑法一并使用。\n");

	if( me->query_skill_mapped("sword") != "murong-sword")
		return notify_fail("你必须运用慕容剑法和慕容刀法一并使用。\n");

	if((int)me->query_skill("blade",1) < 150 )
		return notify_fail("你的基本刀法还没到家，现在运用剑影只会破绽百出。\n");

	if((int)me->query_skill("murong-daofa",1) < 150 )
		  return notify_fail("你的慕容刀法还不到家，无法使用剑影！\n");

	if((int)me->query_skill("sword",1) < 150 )
		return notify_fail("你的基本剑法还没到家，现在运用剑影只会破绽百出。\n");

	if((int)me->query_skill("murong-sword",1) < 150 )
		  return notify_fail("你的慕容剑法还不到家，无法使用剑影！\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，无法使用剑影。\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的内力不够！\n");

	me->clean_up_enemy();

	msg = HIW "$N招式突然变化无常，竟然以刀法的来路运起慕容剑法，显然$N早已把慕容刀法和慕容剑法合二为一。\n"NOR;
	msg += HIW"只见$N手中的"+ weapon->name()+ HIW"刚柔并济，剑尖一闪，陡然变出"+ chinese_number(attack_time)+"个雪白的剑影。\n"NOR;
	message_vision(msg, me);
	if( random((int)me->query("combat_exp")) > target->query("combat_exp") / 4 ) {
		msg = HIB"$n被吓的目瞪口呆，一时之间竟不知所错，招架不及。\n"NOR;
		message_vision(msg, me,target);
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
	}else break;
		me->add("neili", -300);
		me->start_busy(3);
	}
		else {
		skill_name = to_chinese((string)target->query_skill_mapped("dodge"));
		msg = HIC"可是$n毕竟经验老到，早已看穿了剑影中的破绽，轻轻运起"+ skill_name +"，跳开数丈之外！\n"NOR;
		message_vision(msg, me,target);
		me->start_busy(5);
		me->add("neili", -500);
	}
	return 1;
}
