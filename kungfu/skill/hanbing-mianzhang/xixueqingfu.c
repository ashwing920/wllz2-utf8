// xixueqingfu.c 吸血青蝠

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg,dodge_skill;
	object weapon, target;
	int skill,damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = (int)me->query_skill("hanbing-mianzhang",1);

	if(!(me->is_fighting()))
		return notify_fail("「吸血青蝠」只能对战斗中的对手使用。\n");

	if(objectp(weapon = me->query_temp("weapon")))
		return notify_fail("使用「吸血青蝠」时不能携带兵器。\n");

	if(skill < 150)
		return notify_fail("你的「寒冰绵掌」等级不够, 不能使用「吸血青蝠」！\n");

	if((int)me->query_skill("jiuyang-shengong",1) < 150)
		return notify_fail("你的九阳神功不够娴熟，无法发挥「吸血青蝠」的威力！\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你的内力不够使用吸血青蝠！\n");

	if((int)me->query("max_neili") < 3000)
		return notify_fail("你的内力修为不够，无法运用「吸血青蝠」！\n");

	if((int)me->query_skill("dodge",1) < 150 )
		return notify_fail("你的轻功不够，无法运用「吸血青蝠」！\n");

	if(target->is_busy())
		return notify_fail(target->name()+"现在正自顾不暇，赶快放胆攻击吧！\n");

	msg = HIC "$N突然如同「吸血青蝠」，欺近$n的身前，张嘴便向$n的咽喉咬去。\n"NOR;

	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 3 ){
		msg += HIR"$n只觉得咽喉一阵剧痛，定睛一看，$N正附在$n的脖子上，狂吸$n的鲜血！\n"NOR;
		me->add("neili",- 500);
		damage = skill + (int)me->query_skill("dodge",1);
		damage = damage + random(damage);
		if(target->query("neili") > skill) target->add("neili",-skill);
		if(target->query("jingli") > skill) target->add("jingli",-skill);
		target->receive_wound("qi",skill,me);
		target->receive_damage("jing",skill,me);
		if( (int)me->query("qi") < (int)me->query("eff_qi")) me->add("qi",skill);
		if( (int)me->query("jing") < (int)me->query("eff_jing")) me->add("jing",skill);
		if( (int)me->query("jingli") < (int)me->query("max_jingli")) me->add("jingli",skill);
		target->start_busy(random(4));
		me->start_busy(4);
	}
	else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += HIG + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
		me->add("neili",-500);
		me->start_busy(4);
	}
	message_vision(msg, me, target);
	return 1;
}
