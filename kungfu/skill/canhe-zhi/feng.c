// feng.c　封穴式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	skill = (int)me->query_skill("canhe-zhi",1);

	if(!me->is_fighting())
		return notify_fail("「封穴式」只能在战斗中使用。\n");

	if( !target) target = offensive_target(me);
	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("「封穴式」只能对战斗中的对手使用。\n");

	if(me->query_temp("weapon"))
		return notify_fail("使用封穴式时必须空手。\n");

	if((int)me->query_skill("shenyuan-gong",1) < 200)
		return notify_fail("你的神元功修为不够，无法使用封穴式！\n");

	if( skill < 200) 
		return notify_fail("你的参合指还不够纯熟！\n");

	if((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够，不能使出「封穴式」！\n");

	if((int)me->query("neili") < 500 ) 
		return notify_fail("你的内力不足！\n");
		       
	me->clean_up_enemy();
	message_vision(HIY"只见$N手法陡然增快，十指参合，骤散骤离，千变万化，犹如星斗，诡异非常！！\n" NOR, me, target);
	if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 2) {
		switch(random(3)){
			case 1:
			message_vision(CYN"正当$N看得目瞪口呆，不知所措时，$n中指如剑，向$N的笑穴点去！！\n" NOR,target,me);
			tell_object(target,YEL"你只觉得"+ me->query("name")+"的招式十分滑稽，忍不住哈哈大笑了起来...\n"NOR);
			target->apply_condition("canhe_smile",target->query_condition("canhe_smile") + 10);
			target->receive_damage("qi",skill,me);
			break;
			case 2:
			message_vision(CYN"正当$N看得目瞪口呆，不知所措时，$n中指如剑，向$N的气海穴点去！！\n" NOR,target,me);
			message_vision(HIR"$N只觉得胸口一阵气血翻腾，忍不住“哇”的吐出一口鲜血。\n",target);
			target->receive_wound("qi",skill * 2,me);
			break;
			default:
			message_vision(CYN"正当$N看得目瞪口呆，不知所措时，$n中指如剑，向$N的哑穴点去！！\n" NOR,target,me);
			message_vision(HIR"$N只觉被点中的地方一阵麻痹，刚想喊出声来，已.......。\n",target,me);
			target->apply_condition("no_speak",target->query_condition("no_speak") + 10);
			target->receive_damage("qi",skill,me);
			break;
		}
		me->start_busy(3);
		me->add("neili",- 500);
	}
		else {
			message_vision(CYN"可是$n早以识破了$N的招数，轻身躲避，顿时跳开数丈之外。\n"NOR,me,target);
			me->add("neili",-400);
			me->start_busy(5);
		}
	return 1;
}
