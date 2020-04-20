// force.c

#include <ansi.h>

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	if(userp(me)) {
		if((int)me->query("neili") > factor * 2 )
		me->add("neili", - factor);
		else
		me->set("jiali",0);
		factor = 0;
	}

	damage = (int)me->query("neili") / 20 + factor - (int)victim->query("neili")/ 25;
	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&& me->query_skill("force") < random(victim->query_skill("force"))) {
			damage = - damage;
			me->receive_damage( "qi", damage,victim );
			me->receive_wound( "qi", damage /3 ,victim);
			if( damage < 50 ) return RED"$N受到$n的内力反震，闷哼一声。\n"NOR;
			else if( damage < 80 ) return HIR"$N被$n以内力反震，「嘿」地一声退了两步。\n"NOR;
			else if( damage < 160 ) return MAG"$N被$n以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
			else return HIR"$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
		}
	}
	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	return damage;
}
mixed armor_ob(object me, object victim, int damage_bonus,int force_armor)
{
	if (!living(victim) || damage_bonus<0) return damage_bonus;
	if (victim->query("neili") >= force_armor )
		if (force_armor > damage_bonus){
			victim->add("neili",-damage_bonus);
				return HIW"只见$p的"+to_chinese(victim->query_skill_mapped("force"))+"散出连绵真气，将$N的伤害尽数削弱！\n" NOR;
		}else{
			message_vision(MAG"\n$p催动"+to_chinese(victim->query_skill_mapped("force"))+"的护体真气试图削弱$N的伤害！" NOR,me,victim);
			victim->add("neili",-force_armor / 2);
			return damage_bonus-force_armor;
		}
		return damage_bonus;
}
