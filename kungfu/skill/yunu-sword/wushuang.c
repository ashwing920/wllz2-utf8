// wushuang.c 玉女剑法 无双无对

#include <ansi.h>

void remove_effect(object me, int a_amount, int d_amount);
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("无双无对只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("yunu-sword", 1) < 150 )
		return notify_fail("你的玉女金针十三剑不够娴熟，不会使用「无双无对」。\n");
	
	if( (int)me->query_skill("zixia-shengong", 1) < 150 )
		return notify_fail("你的紫霞神功不够娴熟，不会使用「无双无对」。\n");
	
	if( (int)me->query("neili") < 200) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("hsj_wu") ) 
		return notify_fail("你已经在运功中了。\n");

	msg = YEL"$N双手握起" + weapon->name() + "，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$n冲刺！\n"NOR;
	message_vision(msg, me, target);

	skill = (int)me->query_skill("yunu-sword",1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", -skill/4);
	me->set_temp("hsj_wu", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), 2);
	me->add("neili", -200);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	if(!me) return;
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", d_amount);
	me->delete_temp("hsj_wu");
	me->start_busy(4);
}
int clean_up()
{
        return 1;
}
void reset()
{
}
