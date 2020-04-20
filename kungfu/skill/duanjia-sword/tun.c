// tun.c 段家剑法 -气吞山河 
// Written by Doing Lu 1999/1/4

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	object ob;              // 对手的武器
	string msg;
	int damage;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() ||!me->is_fighting(target) )
		return notify_fail("「气吞山河」只能对战斗中的对手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	||(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if(!objectp(ob = target->query_temp("weapon")))
		return notify_fail("对方手中并没有武器。\n");

	if((int)me->query_skill("duanjia-sword",1) < 120 )
		return notify_fail("你的段家剑法还不够纯熟，不能使用「气吞山河」。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你的内力不够，现在无法使用「气吞山河」。\n");
	
	me->add("neili", -300);

	msg = HIY"$N使出段家剑法的绝技「气吞山河」，手中"+ weapon->name()+"夹着剑气直刺$n的右手。\n";

	me->start_busy(2);
	if( random((int)me->query_skill("force") ) > random((int)target->query_skill("force")))
	{
		if (ob->query("ownmake"))
		{
			damage = (int)me->query_skill("duanjia-sword",1) + (int)me->query_skill("kurong-changong",1);
			damage = damage + random(damage);
			msg += HIR"$p忙用" + ob->query("name") + "招架，只觉得虎口剧震，兵器完好无损。\n";
			msg += "冷不防却被$P的剑气击中，不禁退了个趔趄。\n"NOR;
			target->receive_damage("qi",damage,me);
		} 
		else
		{
			msg += HIW " $p连忙招架，只听见「啪」地一剧响，$p手中的" + ob->name()+ "已经断为数截，激飞上天！\n"NOR;
			ob->unequip();
			ob->move(environment(target));
			ob->set("name", "断掉的" + ob->query("name"));
			ob->set("value", 0);
			ob->set("weapon_prop", 0);
			ob->set("no_get",1);
			target->reset_action();
			target->start_busy(2);
		}
	} 
	else
	{
		msg += "$p真气贯注" + ob->query("name") + "，和$P剑气相交，冒出点点火光。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
