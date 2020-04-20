#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void check_pfm(object me, object target, object ob);

int perform(object me, object target)
{
	object ob;
	int skill,ap,dp,i,damage,neili,p;
	string msg,*limbs;
	
	if(!target) target = offensive_target(me);
	if(!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「碧焰」攻击只能对战斗中的对手使用。\n");
      
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「碧焰」！\n");	

	skill = (int)me->query_skill("chousui-zhang",1);

	if( skill < 150 )
		 return notify_fail("你的星宿毒掌还不够娴熟，无法使用「碧焰」进行攻击。\n");

	if((int)me->query_skill("huagong-dafa",1) < 150 )
		 return notify_fail("你的化功大法修为不够，无法使用「碧焰」进行攻击。\n");

	if((int)me->query_skill("poison",1) < 150)
		 return notify_fail("你的基本毒技还不够，无法使用「碧焰」进行攻击。\n");	 

	if((string)me->query_skill_mapped("strike") != "chousui-zhang")
		return notify_fail("你必须用抽髓掌才能使用「碧焰」进行攻击。\n"); 

	if((string)me->query_skill_mapped("force") != "huagong-dafa")
		return notify_fail("你所用的内功无法进行「碧焰」攻击。\n");

	if((int)me->query("max_neili") < 500) 
		 return notify_fail("你的内力修为太弱，无法驱动「碧焰」进行攻击。\n");

	if((int)me->query("neili") < 300)
		 return notify_fail("你现在真气太弱，使不出「碧焰」进行攻击。\n");	   

	if(!objectp(ob = present("huo yan", environment(me))))
		 return notify_fail("没有火堆怎么驱动「碧焰」进行攻击？\n");

	if(target->query_condition("xx_poison") > 100)
		 return notify_fail(target->name()+"经身中无数剧毒，你不用再进行「碧焰」攻击了。\n");

	me->clean_up_enemy();
	message_vision(HIG"$N右手指向"HIR"火堆"HIG"，默不作声的注视着火焰，左掌按胸，口中喃喃的不知说些什么。\n"NOR,me);
	
	i = (int)me->query_skill("chousui-zhang", 1);
	neili = (int)me->query("neili");
	ap = (int)me->query("combat_exp")/1000 * i * me->query_str();
	dp = (int)target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_dex();
	
	if (ap < 1) ap = 1;
	if (dp < 1) dp = 1;
	
	me->add("neili", -300);

	msg = HIR"然后$N突然双掌向前平平推出，但见火焰微微颤动了两下，吐出一道"GRN"碧焰"HIR"，射向$n的$l！\n\n"NOR;	

	if(random(ap) > dp/2){
		damage = random(i)*2+me->query("jiali")*2;
		if(neili > (int)target->query("neili")*2) damage = damage*2;
		if (damage > 700) damage = 700;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2, me);
		target->apply_condition("xx_poison",((int)me->query_skill("poison", 1)/2) + target->query_condition("xx_poison"));
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		me->start_busy(3);
	}
	else
	{
		me->start_busy(5);
		msg += HIY"$p全力向后一纵一闪，凶险万分地避开了那急速而来的$w"HIY"！\n\n" NOR;
	}	
	limbs = target->query("limbs");
	msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
	msg = replace_string(msg, "$w", GRN"碧焰"NOR);
	message_vision(msg, me, target);
	COMBAT_D->report_status(target);
	return 1;
}
