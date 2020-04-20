// fugu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int str,dex,time;
	string msg,dodge_skill;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("你必须在战斗中才能发挥剑意。\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你必须空手才可以发挥剑意。\n");

	if( (int)me->query_skill("luoying-zhang", 1) < 150 )
		return notify_fail("你的落英神剑掌不够娴熟，无法发挥剑意。\n");

	if( (int)me->query_skill("bibo-shengong", 1) < 150 )
		return notify_fail("你的碧波神功修为不够，无法发挥剑意。\n");

	if((string)me->query_skill_mapped("dodge")!= "anying-fuxiang")
		return notify_fail("剑意必须借助暗影浮香一起发挥威力。\n");

	if((int)target->query_temp("jianyi"))
		return notify_fail(target->name()+"已经被你的剑意所伤，再对其施展剑意已经毫无意义了。\n");

	if((int)me->query("neili") < 300 )
		return notify_fail("你的内力不够了。\n");

	time = me->query_skill("luoying-zhang",1) / 10;
	me->clean_up_enemy();

	msg = HIC"$N运用暗影浮香，身法陡然增快，突然化作数个身影，迅速将$n包围起来。\n"
	"待$n深陷迷阵之时，$N伺机冲到$n身后，五指并拢，如利刃一般刺向$n的中枢。\n"NOR;

	if(random(me->query("combat_exp")) > target->query("combat_exp") / 3){
		msg += HIW"只听见“啪”的一声巨响，$N的剑掌已经刺中$n的中枢，$n一声哀嚎，竟觉全身乏力。\n"NOR;
		str = (int)me->query_str() / 5;
		dex = (int)me->query_str() / 5;
		target->add_temp("apply/strength",-str);
		target->add_temp("apply/dexerity",-dex);
		target->set_temp("jianyi",1);
		me->add("neili", -300);
		me->start_busy(3);
		call_out("remove_jianyi",time,target,str,dex);
	} else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += HIW + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	return 1;
}
void remove_jianyi(object target,int str,int dex)
{
	if(!target || !environment(target)) return;
	target->add_temp("apply/strength",str);
	target->add_temp("apply/dexerity",dex);
	tell_object(target,"你觉得失去的劲力已经逐渐恢复了。\n");
}
