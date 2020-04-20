// slzy.c 神龙在野

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
 
        if( !target ) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target))
                return notify_fail("「神龙在野」只能在战斗中使用。\n");

        if(objectp(weapon = me->query_temp("weapon")))
                return notify_fail("使用神龙在野必须空手。\n");

        if((int)me->query_str() < 35)
                return notify_fail("你的膂力不够, 目前还不能使用这项绝技！\n");

        if((int)me->query_skill("xianglong-zhang",1) < 200)
                return notify_fail("你的降龙十八掌修为不够, 不能使用神龙在野！\n");
                
        if( (int)me->query_skill("huntian-qigong",1) < 200)
                return notify_fail("你的混天气功修为不够，无法使用「神龙在野」。\n");
 
        if( (int)me->query("neili") < 500)
                return notify_fail("你的内力不够使出「神龙在野」！\n");
        
        if((int)me->query("jiali") < 1)
                return notify_fail("你没有设置加力，怎么能使出「神龙在野」？\n");
        
        me->clean_up_enemy();
        msg = HIC"只见$N运起内力，大喝一声：「神龙在野」，拳法陡然变快！\n"NOR;
        message_vision(msg, me,target);
        if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 6) {
        msg = CYN"结果$p被$P攻了个措手不及！\n" NOR;
        message_vision(msg, me,target);
        
        for(i = 0; i < 8; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                target->start_busy(1);
                me->set_temp("action_flag",1);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),0);
                me->set_temp("action_flag",0);
        }else break;
                me->add("neili", -500);
                me->start_busy(5);
}
        else {
                msg = "$n运用轻功，闪开了$N的攻击！\n";
                message_vision(msg, me,target); 
                me->start_busy(2);
        }
        return 1;
}
