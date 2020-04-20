// zhi.c 孤注一掷

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int lvl,jiali;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("「孤注一掷」只能对战斗中的对手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你不能使用武器！\n");

	lvl = (int) me->query_skill("canhe-zhi",1);
	jiali = (int)me->query("jiali");

	if((int)me->query_skill("shenyuan-gong",1) < 120)
		return notify_fail("你的神元功修为不够，无法使用「孤注一掷」。\n");

	if( lvl < 120 )
		return notify_fail("你的参合指太生疏，不会使用「孤注一掷」。\n");

	if( jiali <= 0)
		return notify_fail("你的加力不足，参合指的绝技「孤注一掷」形同虚设！\n");

	if((int)me->query("neili") < jiali )
		return notify_fail("你的内力不够，现在无法使用「孤注一掷」字决。\n");

	me->add("neili", -jiali);
	msg = HIW"鼓动真气，瞬间将真气集于指尖，抖的向$n的胸前指去！\n";

	if( random((int)me->query("neili") + (int)me->query_skill("canhe-zhi",1) * 10 ) 
	> random((int) target->query("neili") + (int)target->query_skill("dodge",1) * 10)) {
		msg += HIR"$p冷不防的被$N点中胸前，哇的一声吐出一口鲜血。\n" NOR;
		target->receive_wound("qi",random(lvl) + jiali);
	} else {
		msg += HIY"$n冷笑一声，轻飘淡写，早已避开了$N的攻击。\n" NOR;
	}
	me->start_busy(3);
	message_vision(msg, me, target);
	return 1;
}
