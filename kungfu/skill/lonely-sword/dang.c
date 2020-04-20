// ba.c　四两拔千斤

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int extra, forces;
	object weapon;
	string msg;
	extra = (int)me->query_skill("lonely-sword",1);

	if ( extra < 120) return notify_fail("你的独孤九剑还不够纯熟！\n");

	forces = (int)me->query("jiali");

	if((int)me->query("neili") < 400)
		return notify_fail("你的内力不够使出「荡剑式」！\n");

	if((int)me->query("neili") < forces *3 ) 
		return notify_fail("你的内力不足！\n");
	if((int)me->query("qi") < 200 ) 
		return notify_fail("你的内力不足！\n");

	if(!target) target = offensive_target(me);
	if(!target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「荡剑式」只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
			
	me->clean_up_enemy();
	weapon = me->query_temp("weapon");
	msg = weapon->query("name");
	message_vision(HIY"\n$N气沉丹田，手中"+ msg + HIY"剑尖点地，纵身弹起，喝道：荡剑式！！\n" NOR, me, target);
	message_vision(HIW"\n瞬间尘沙飞扬，剑气凌人，$N人剑合一，飞身朝$n袭去！！！\n" NOR, me,target);
	if(!target->is_busy()) target->start_busy(1);
	target->receive_wound("qi",forces * 3,me);
      COMBAT_D->report_status(target);
	message_vision(HIY "\n$n还没反应过来，$N的"+ msg + HIY"划出的剑气已经划向$n的胸口！！\n" NOR, me, target);
	me->clean_up_enemy();
      me->set_temp("action_flag",1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), SKILL_USAGE_ATTACK);
	message_vision(HIY  "\n$N凌空翻身，向$n刺去了致命的一剑！！！\n" NOR, me, target);
	me->clean_up_enemy();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), SKILL_USAGE_ATTACK);
      me->set_temp("action_flag",0);
	me->start_busy(3);
	me->add("neili", -forces*3);
	return 1;
}
