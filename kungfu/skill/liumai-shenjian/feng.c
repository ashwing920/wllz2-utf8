// feng.c 六脉神剑 - 封

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「封」字决指法只能对战斗中的对手使用。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你不能使用武器！\n");

	if( (int)me->query_skill("liumai-shenjian", 1) < 120 )
		return notify_fail("你的六脉神剑太生疏，不会使用「封」字决。\n");

	if((int)me->query_skill("kurong-changong",1) < 150)
		return notify_fail("你的枯荣禅功不够娴熟，无法使用六脉神剑特殊攻击法！\n");

	if ( me->query("neili") < 200)
		return notify_fail("你的内力不够，现在无法使用「封」字决。\n");
	me->add("neili", - 200);

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = HIY "$N长出一口气，使出六脉神剑「封」式，指指点点，剑气如潮而至。\n";

	if( random( me->query("neili") + me->query_skill("dodge") * 10 ) >
		random((int)target->query("neili") + (int)target->query_skill("dodge") * 5) ) {
		msg += HIR " $p强做精神，左遮右挡，无法还手！\n" NOR;
		target->start_busy( (int)me->query_skill("liumai-shenjian", 1) / 40 );
	} else {
		msg += "可是$p身形一错，已飘然脱离$P的攻击。\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);

	return 1;
}
