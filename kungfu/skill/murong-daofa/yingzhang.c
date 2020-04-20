
#include <ansi.h>

inherit F_SSERVER;

int perform(object me,object target)
{
	int d=me->query_skill("taxue-steps",1)/5;
	int j=me->query_skill("murong-daofa", 1)/5;
	int i=me->query_skill("xingyi-zhang", 1)/5;
        object weapon = me->query_temp("weapon");
        
        if(!me->is_fighting())
        	return notify_fail("刀影掌只能在战斗中使用。\n");

        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("刀影掌只能对战斗中的对手使用。\n");                

        if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("你的内功还未练成，不能使用刀影掌！\n");    

        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("你的刀法还未练成，不能使用刀影掌！\n");        

        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "murong-daofa")
                return notify_fail("你手里没有刀，无法使用刀影掌！\n");

        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("你的掌法还未练成，不能使用刀影掌！\n");  

        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("你的内功不是神元功，无法使用刀影掌！\n");      

        if(me->query_skill_mapped("strike") != "xingyi-zhang"
        || me->query_skill_prepared("strike") != "xingyi-zhang")
		return notify_fail("你没有用掌，无法使用刀影掌！\n");

        if(me->query_skill_mapped("parry") != "xingyi-zhang")
		if(me->query_skill_mapped("parry") != "murong-daofa")
                	return notify_fail("你的招架功夫不对，无法使用刀影掌！\n");

        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");

        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的基本掌法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");     

        if((int)me->query("neili") < 600 )
                return notify_fail("你现在内力不足，不能使用刀影掌！\n");      
        
        message_vision(HIR"\n$N大吼一声使出刀影掌，掌随刀走，刀光中夹杂着阵阵掌风一起奔向$n！\n"NOR, me,target);
	
	me->add("neili", -250); 
	me->add_temp("apply/dodge", d); 
	me->add_temp("apply/attack", (i+j)/2); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        weapon->unequip(); 
	me->add_temp("apply/strike", i/2); 
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
	me->add_temp("apply/strike", -i/2); 
        weapon->wield(); 
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
	me->add_temp("apply/attack", -((i+j)/2)); 
	me->add_temp("apply/dodge", -d); 
        me->start_busy(3);
        target->start_busy(1);
        return 1;
}
