//天下无狗 tianxia.c

#include <ansi.h>

inherit F_SSERVER;

string *per_msg = ({
	HIC"打狗棒之棒打双犬\n"NOR,
	HIB"打狗棒之拨草寻蛇\n"NOR,
	HIR"打狗棒之打草惊蛇\n"NOR,
	HIM"打狗棒之拨狗朝天\n"NOR,
	HIG"打狗棒之压扁狗背\n"NOR,
	HIW"打狗棒之恶狗拦路\n"NOR,
	HIW"打狗棒之棒打狗头\n"NOR,
	HIW"打狗棒之天下无狗\n"NOR,
});
int perform(object me, object target)
{
	object weapon,ob;
	int skill,lvl,attack_time,i;
	string msg,name;

	lvl = (int)me->query_skill("dagou-bang",1);
	if( lvl <= 150) attack_time = 4;
	if( lvl <= 250 && lvl > 150 ) attack_time = 6;
	if( lvl <= 350 && lvl > 250 ) attack_time = 8;
	if( lvl > 350 ) attack_time = 12;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「天下无狗」只能在战斗中使用。\n");

	if( (int)me->query_skill("dagou-bang", 1) < 150 )
		return notify_fail("你的「打狗棒法」不够娴熟，不能使用外功！\n");

	if( (int)me->query_skill("huntian-qigong" , 1) < 150 )
		return notify_fail("你的「混天气功」不够娴熟，不能使用外功！\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");
		
	if(!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "staff" )
		return notify_fail("你的兵器类型不对。\n");

	skill = me->query_skill("dagou-bang");

	me->clean_up_enemy();
	ob = me->select_opponent();
	weapon = me->query_temp("weapon");
	name = weapon->query("name");

	msg = HIY "$N手中"+ name +"一挥，随即大喝一声“天下无狗”，招式瞬间突然变快。\n"NOR;
	message_vision(msg, me, target);
	if( random((int)me->query("combat_exp")) > target->query("combat_exp") / 4) {
	for(i = 0; i < attack_time; i++)
		if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
		me->set_temp("action_flag",1);
		msg = per_msg[random(sizeof(per_msg))];
		message_vision(msg, me, target);
		if (!weapon->query("equipped")) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set_temp("action_flag",0);
	}else   break;
		me->add("neili", -200);
		me->start_busy(2);
	}
		else {
			msg = "却见$n不慌不忙的躲开了$N的招式。\n";
			message_vision(msg, me, target);
			me->add("neili", -400);
			me->start_busy(4);
	}
	return 1;
}

