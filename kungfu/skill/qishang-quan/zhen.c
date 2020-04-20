// zhen 震惊百里
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int damage;

	if( !target ) target = offensive_target(me);
	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("震惊百里只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用震惊百里！\n");

	if( me->query("jiali") <= 0)
		return notify_fail("你的加力太弱，无法使用震惊百里！\n");

	if( (int)me->query_skill("qishang-quan", 1) < 120)
		return notify_fail("你的七伤拳还不够娴熟，无法震惊百里。\n");

	if( (int)me->query_skill("jiuyang-shengong", 1) < 120)
		return notify_fail("你的九阳神功还不够娴熟，无法震惊百里。\n");

	if( (int)me->query("neili", 1) < me->query("jiali"))
		return notify_fail("以你的目前的内力没有办法发出震惊百里。\n");

	msg = HIR"$N凝神运功，双掌青筋暴起，瞬间将内力聚集于掌心，猛的向$n的胸口拍去！\n";

	if ((random(me->query_skill("force")) > target->query_skill("force")/3)){
		me->add("neili",- (int)me->query("jiali") * 3);
		me->start_busy(2);
		damage = (int)me->query_skill("qishang-quan", 1);
		damage += random(damage) + ((int)me->query("jiali") * 3);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi", damage / 2,me);
		msg += HIR"$n闪躲不及，被$N的掌风击中，「哇」的吐出一口鲜血！胸口留下了一双熏黑的掌印！\n"NOR;
		COMBAT_D->report_status(target);

	} else
	{
		me->start_busy(4);
		msg += HIW"$n强运内功，掌心与$N碰在一起，四周顿时泛起一道强烈的掌风！\n"NOR;
		if( target->query("neili") >= 0) target->add("neili",-100);
	}
	message_vision(msg, me, target);
	return 1;
}
