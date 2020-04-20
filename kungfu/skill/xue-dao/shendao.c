// shendao.c  血刀「祭血神刀」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	
	if(!target ) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「祭血神刀」只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("必须装备刀才能使用「祭血神刀」！\n");

	if((int)me->query_skill("xue-dao", 1) < 120 )
		return notify_fail("你血刀刀法不够娴熟，使不出「祭血神刀」。\n");

	if((int)me->query_skill("xuehai-mogong", 1) < 120 )
		return notify_fail("你血海魔功火候不够，使不出「祭血神刀」。\n");

	if((int)me->query("neili") < 200)
		return notify_fail("你的内力不够了。\n");

	if((int)me->query("MKS") <= 0)
		return notify_fail("血海魔功需要以仇杀次数来发挥它的伤害力。\n");
		
	me->clean_up_enemy();

	msg = HIC"$N右手持刀向左肩一勒，一阵血珠溅满刀面，紧接着右臂抡出......\n"
		HIR"一道刀光划出，一片血光裹住刀影向$n的颈部劈去。\n"NOR;
	
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4){
		damage = (int)me->query_skill("xue-dao") + (int)me->query_skill("xuehai-mogong");
		damage += (int)me->query("MKS") / 100;
		damage += random(damage);
		msg += HIR"$n急忙侧身避让，但血刀疾闪，只觉眼前一阵血红，刀刃劈面而下....\n"
			"只见$n颈部一道血口划开，鲜血溅在$N的"HIW + weapon->name() + HIR"上，$n惨声大嚎！\n"NOR;
		me->add("neili", -200);
		me->start_busy(3);
		target->start_busy(random(2));
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage,me);
	} else
	{
		msg += HIW"可是$n侧身避让，不慌不忙，躲过了$N的一记「祭血神刀」。\n"NOR;
		me->start_busy(5);
		me->receive_wound("qi",10,me);
		me->add("neili", -150);
	}
	message_vision(msg, me, target);
	return 1;
}
