// feng.c 天山杖法「冰封」

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int time;
	object weapon;
	string msg,weapon_name;

	if( !target ) target = offensive_target(me);
	if( !target||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「冰封」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")

	if((int)me->query_skill("huagong-dafa",1) < 150)
		return notify_fail("你的化功大法不够娴熟，无法使用「冰封」。\n");

	if( (int)me->query_skill("tianshan-zhang", 1) < 150 )
		return notify_fail("你的天山杖法不够娴熟，不会使用「冰封」。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你的内力不够了。\n");

	if( target->is_busy())
		return notify_fail(target->name() + "已经被冰封了，动也动不了。\n");

	if( me->is_busy())
		return notify_fail("你现在正忙着。\n");

	if (!me->visible(target))
		return notify_fail("你看不到"+target->name()+"。\n");

	me->clean_up_enemy();
	weapon_name = weapon->query("name");
	msg = HIW"$N使出天山杖法中的精髓「"HIB"冰封"HIW"」，手中"+ weapon_name+ HIW"突然加速旋转，配合着真气卷起一道气浪，向$n扑去！\n"NOR;
	me->start_busy(2);
	me->add("neili",- 200);
	time = (int)me->query_skill("tianshan-zhang") / 40;

	if(time<3) time = 3;
	if( time > 10 ) time = 10;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
		msg += HIB "$p闪躲不及，被$P卷来的气浪罩住，动弹不得！\n" NOR;
		target->start_busy(time);
	} else {
		if(time > 6) time = 6;
		me->start_busy(time/2);
		msg += HIY"$p纵身飞起，跳开数丈之远，躲开了$P的攻击。\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}
