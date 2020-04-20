// lianquan 玉女素心剑法<<总决式>>

#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	mapping myfam;
	string msg;
	int skill, jing_cost;

	skill = (int)me->query_skill("meinv-quan",1);
	jing_cost = (int)me->query("int") - 45;

	if(!mapp(myfam = me->query("family")) || myfam["family_name"] != "古墓新派")
		return notify_fail("可能缺乏师尊的指导，你总是难以理解美女拳法总诀式的奥妙。\n");

	if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。\n");
 
	if(objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")))
		return notify_fail("练美女拳法必须空手。\n");

	if((int)me->query_skill("tianluo-diwang",1)<120)
		return notify_fail("你的天罗地网势火候不够，不能用总诀式练拳法.\n");
		
	if(skill < 120)
		return notify_fail("你的美女拳法法等级不够, 不能用总诀式练！\n");

	if((int)me->query("neili") < 100)
		return notify_fail("你的内力不够，没有力气练玉女素心剑！\n");
 
	if((int)me->query("jing") < -jing_cost )
		return notify_fail("你现在太累了，无法集中精神演练美女拳法！\n");

	if((skill * skill * skill) / 10 > (int)me->query("combat_exp"))
		return notify_fail("可能是实战经验不足，你无法演练出更高深的美女拳法了。\n");

	msg = CYN "$N"CYN"演练了一套"HIM"美女拳法"NOR"。\n";
	message_vision(msg, me);

	me->add("neili", - (int)me->query("max_neili") / 80);
	me->add("jing", - jing_cost);
	me->add("qi",-15);
	me->improve_skill("meinv-quan", ((int)me->query_skill("meinv-quan",1)+((int)me->query_skill("meinv-quan",1)/2)));
	msg = MAG"$P的「美女拳法」进步了！\n"NOR;
	me->start_busy(random(2));
	message_vision(msg, me);
	return 1;
}
