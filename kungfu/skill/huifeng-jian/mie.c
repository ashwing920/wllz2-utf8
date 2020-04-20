// mie.c  回风拂柳剑法「灭剑」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg,weapon_name;
	object weapon;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「灭剑」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("开什么玩笑，没装备剑就想使「灭剑」？\n");

	if ((int)me->query_skill("huifeng-jian", 1) < 120 )
		return notify_fail("你的回风拂柳剑法不够娴熟，还使不出「灭剑」。\n");

	if ((int)me->query_skill("linji-zhuang", 1) < 120 )
		return notify_fail("你的临济十二庄火候不够，「灭剑」不成招式。\n");

	if ((int)me->query("max_neili") < 800)
		return notify_fail("你的内力修为不足，无法运足「灭剑」的内力。\n");

	if((string)me->query_skill_mapped("sword") != "huifeng-jian")
		return notify_fail("你没有激发回风拂柳剑为剑式，怎么能用「灭剑」呢？\n");

	if((int)me->query("neili") < 600)
		return notify_fail("你的内力不足，无法使用「灭剑」。\n");

	me->clean_up_enemy();
	weapon_name = weapon->query("name");
	msg = HIC
"$N手中"+ weapon_name +HIC"剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐渐逼近$n，$n看到漫
天剑光，抽身后跃，只这一刹，漫天剑影化为一剑直刺$n前胸，快捷无伦，只有一剑！\n"NOR;

	if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
	   random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
	{
		me->start_busy(2);
		damage = (int)me->query_skill("sword") + me->query_skill("force",1);
		damage = damage + random(damage);
		target->receive_damage("qi", damage/3,me);
		target->receive_wound("qi", damage,me);
		target->receive_damage("jing",damage,me);
		msg += HIC"$n根本没法躲避，一式「回风拂柳剑」的绝招「灭剑」端端正正扎进在$n胸口！\n$n一低头："+ weapon_name + HIC"自胸口拔出，鲜血正喷射而出！\n"NOR;
		me->add("neili",-600);
	} else
	{
		me->start_busy(2);
		msg += HIY"可是$p轻轻一笑，侧身右转，伸出两指，正弹在$P的剑上，"+ weapon_name + HIY"在$p身侧划过，毫发无伤。\n"NOR;
		me->add("neili", -300);
	}
	message_vision(msg, me, target);
	return 1;
}
