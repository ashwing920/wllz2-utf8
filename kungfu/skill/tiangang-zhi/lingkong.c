// lingxiao.c 天罡指穴法 「凌空指穴」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「凌空指穴」只能在战斗中使用。\n");

	if((int)me->query_str() < 35)
		return notify_fail("你臂力不够,不能使用这一绝技！\n");

	if((int)me->query_skill("linji-zhuang",1) < 150)
		return notify_fail("你临济十二庄的功力不够不能使用凌空指穴！\n");

	if((int)me->query_skill("finger",1) < 150)
		return notify_fail("你的指法修为不够,目前还不能使用凌空指穴绝技！\n");

	if((int)me->query("neili") < 100)
		return notify_fail("你内力现在不够, 不能使用凌空指穴！\n");

	if(me->query_temp("weapon"))
		return notify_fail("运用凌空指穴时必须空手。\n");

	if(living(target) && target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg =HIY
"$N使出天罡指穴法绝技「凌空指穴」，回过身来，背后竟似生了眼睛一
般，左手食中二指向$n接连戳去，一连七指，全是对向$n的头脸与前
胸重穴。$n不及攻敌，拼力躲避$N指力顿时动作大乱。\n"NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ){
		msg +=  HIG "结果$p被$P指力点中几处穴道！\n" NOR;
		target->start_busy( (int)me->query_skill("tiangang-zhi",1) / 60 + 2);
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

