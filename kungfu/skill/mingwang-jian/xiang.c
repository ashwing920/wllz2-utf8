// xiangmo-wu.c
// 降魔舞

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i,damage,level,lvl;
 
	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「降魔舞」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_dex() < 30)
		return notify_fail("你的身法不够, 目前还不能使用这项绝技！\n");

	if((int)me->query_skill("force",1) < 120)
		return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");

	if((int)me->query_skill("mingwang-jian",1) < 120)
		return notify_fail("你的剑法修为不够，目前不能使用降魔舞！\n");

	if( (int)me->query("neili") < 300)
		return notify_fail("你的内力不够！\n");


	if((int)me->query_skill("mingwang-jian",1) > 350) lvl = 12;
	else if((int)me->query_skill("mingwang-jian",1) > 250) lvl = 8;
	else if((int)me->query_skill("mingwang-jian",1) > 150) lvl = 6;
	else lvl = 4;


	me->clean_up_enemy();
	msg = HIY"\n$N附剑翻身，剑尖一闪，喝道：「"HIW"降魔舞"HIY"」，手中"+ weapon->name()+ HIY"绽开数朵剑花，向$n刺去！！\n" NOR;
	message_vision(msg, me,target);

	for(i = 0; i < lvl; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, weapon,1);
	}else break;
	me->add("neili", -300);
	me->start_busy(4);
	return 1;
}
