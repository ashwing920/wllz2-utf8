// zhuihun.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int skill,i;
	object weapon;

	skill = (int)me->query_skill("wudu-bian",1);
	
	if( !target ) target = offensive_target(me);
	if( !target ||!target->is_character() || !me->is_fighting(target))
		return notify_fail("追魂鞭只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你手中无鞭，如何运用追魂鞭呢？\n");

	if( skill < 200)
		return notify_fail("你的五毒鞭法还不够熟练！\n");

	if((int)me->query_skill("wudu-shengong",1) < 200)
		return notify_fail("你的五毒神功还不够娴熟，无法使用五毒追魂鞭！\n");

	if((int)me->query_skill("wudu-xinfa",1) < 200)
		return notify_fail("你的五毒心法还不够娴熟，无法使用五毒追魂鞭！\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，无法使用五毒追魂鞭。\n");

	if((int)me->query("neili") < 400)
		return notify_fail("你的内力不够使用五毒追魂鞭！\n");

	me->clean_up_enemy();
	me->add("neili",-400);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", skill);
	msg = HIR "\n$N力灌鞭梢，手中的"+weapon->query("name")+ HIR"＂叭＂的一声，象条毒龙般向$n钻去！\n" NOR;
	message_vision(msg, me,target);
	if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		for(i=0;i<8;i++)
			if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
			msg = HIR "\n$N力灌鞭梢，手中的"+weapon->query("name")+ HIR"＂叭＂的一声，象条毒龙般向$n钻去！\n" NOR;
			message_vision(msg, me,target);
			if (!weapon->query("equipped")) break;
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
		}else break;
	}
	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -skill);
	me->start_busy(4);
	return 1;
}
