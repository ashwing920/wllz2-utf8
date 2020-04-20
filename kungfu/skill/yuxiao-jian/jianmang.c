//Cracked by Kafei
// jianmang.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int speed, damage, sword;

	if( !target) target = offensive_target(me);
	if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
		return notify_fail("剑芒只能对战斗中的对手使用。\n");

	if( !objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能运用「剑芒」？！\n");

	if((int)me->query_temp("jianmang") )
		return notify_fail("你气血翻涌，无法运用「剑芒」！\n");

	if((int)me->query_skill("yuxiao-jian",1) < 180)
		return notify_fail("你修为还不够，还未领悟「剑芒」！\n");

	if((int)me->query_skill("bibo-shengong", 1) < 180 )
		return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");

	if((string)me->query_skill_mapped("force") != "bibo-shengong")
		return notify_fail("你所用的内功与「剑芒」心法相悖！\n");

	if((int)me->query("max_neili") <= 1200 )
		return notify_fail("你的内力修为不足，劲力不足以施展剑芒！\n");

	if((int)me->query("neili") <= 600 )
		return notify_fail("你的内力不够，劲力不足以施展剑芒！\n");

	if((int)me->query("jingli") <= 200 )
		return notify_fail("你的精力有限，不足以施展剑芒！\n");

	damage = (int)me->query_skill("force") + (int)me->query_skill("qimen-wuxing",1);
	damage = damage/6;
	sword = (int)me->query_skill("sword")/3;

	if ( userp(me) ) {
		me->add("neili", -600);
		me->add("jingli",-150);
		if ( damage > (int)weapon->query("weapon_prop/damage") * 3)
			damage = (int)weapon->query("weapon_prop/damage") * 3;
		else weapon->add("rigidity",1);
	}

	me->set_temp("jianmang",1);
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);

	message_vision(HIC
"$N猛提一口真气，手中"+weapon->name()+HIC"嗡嗡作响，"+weapon->name()+HIC"渐渐变成惨碧半透明色，\n"+
HIG"一团青碧色毫芒从剑柄处直游至剑尖 ......\n"
+weapon->name()+HIG"前端蓦地伸出三尺"+HIW"剑芒"+HIG"，忽伸忽缩，吞吐不定，看上去诡异绝伦！！！\n"NOR, 
me);
	
	call_out("remove_effect1", sword/2, me, weapon,damage);
	call_out("remove_effect2", sword*2/3, me);
	return 1;
}

void remove_effect1(object me, object weapon,int damage) 
{
	if (!me) return;

	me->add_temp("apply/attack", -damage);

	if (!weapon) {
		me->set_temp("apply/damage", 0);
		return;
	}

	if((int)weapon->query("weapon_prop/damage") < 150) {
		message_vision(HIW"\n只听得一声清响，$N手中"+weapon->name()+HIW"经不住内力冲击，已裂成碎片！！\n"NOR,me);
		weapon->set("name",weapon->name()+"的碎片");
		weapon->unequip();
		weapon->move(environment(me));
		me->set_temp("apply/damage", 0);
	}
	else {
		me->add_temp("apply/damage", -damage);
		message_vision(HIY"\n$N手中"+weapon->name()+HIY"“咯”的一声轻响，附在剑上的青芒已消失得无影无踪。\n"NOR, me);
	}
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("jianmang");
	tell_object(me, HIG"\n你经过一段时间调气养息，经脉气血已运转如常。\n"NOR); 
}
