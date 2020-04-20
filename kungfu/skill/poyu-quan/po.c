// poyu.c 破玉

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「破玉拳法」只能在战斗中使用。\n");

	if((int)me->query_skill("huashan-neigong",1) < 150)
		return notify_fail("你华山内功的功力不够不能使用凌空指穴！\n");

	if((int)me->query_skill("cuff",1) < 150)
		return notify_fail("你的指法修为不够,目前还不能使用凌空指穴绝技！\n");

	if((int)me->query("neili") < 100)
		return notify_fail("你内力现在不够, 不能使用凌空指穴！\n");

	if(me->query_temp("weapon"))
		return notify_fail("运用破玉拳法时必须空手。\n");

	if(living(target) && target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg =HIY
"$N使出劈石破玉拳的绝学破玉拳法，一式「粉石碎玉」双拳齐齐
捶向$n的胸口重穴。$n不及攻敌，拼力躲避$N拳风顿时动作大乱。\n"NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ){
		msg +=  HIG "结果$p被$P拳风打中胸口一时停顿！\n" NOR;
		target->start_busy( (int)me->query_skill("poyu-quan",1) / 60 + 2);
		me->add("neili", -100);
	}
	else
	{
		msg += HIM "$p情急智生，狠力一跃，退出老远。\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}

