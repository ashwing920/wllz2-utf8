// po.c 「总诀式」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon;
	int skill,skill_base,jing_cost,exp;

	skill_base= (int)me->query_skill("sword",1);
	skill = (int)me->query_skill("lonely-sword",1);
	jing_cost = (int)me->query("int") - 45;

	if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。\n");
	if( me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先去找一把剑。\n");

	if(environment(me)->query("restrict_action")) 
		return notify_fail("这里不能做这件事情。\n");

	if( !skill || (skill < 200))
		return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");

	if( me->query_skill_mapped("sword") != "lonely-sword")
		return notify_fail("你没有激发独孤九剑，如何能够演练独孤九剑呢？\n");

	if( skill_base/2 <= skill/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	if( me->query("neili") < (int)me->query("max_neili") / 20 )
		return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");

	if( me->query("jing") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");

	exp= (int)me->query("combat_exp");
	if( skill*skill*skill/10>exp )
		return notify_fail("你的实战经验不够，无法体会「总诀式」！\n");

	msg= MAG"$N使出独孤九剑之「总诀式」，将手中"+weapon->name()+ NOR + MAG"随意挥舞击刺。\n"NOR;
	message_vision(msg, me);

	me->add("neili", - skill);
	me->add("jing", jing_cost);

	if( skill < 200)
	me->improve_skill("lonely-sword",30);
	else if (skill < 300)
	me->improve_skill("lonely-sword",30 + (int)me->query_con() + random((int)me->query_int()- 9));
	else if (skill < 400)
	me->improve_skill("lonely-sword",30 + (int)me->query_con() + random((int)me->query_int()*2-9));
	else if (skill < 500)
	me->improve_skill("lonely-sword",30 + (int)me->query_con() + random((int)me->query_int()*4-9));
	else me->improve_skill("lonely-sword",30+random((int)me->query_int()*8-9));
	tell_object(me,HIC"通过演练，你的「独孤九剑」逐渐熟练了！\n"NOR);
	me->start_busy(random(3));
	return 1;
}
