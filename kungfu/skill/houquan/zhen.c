// zhen.c 猴拳「震」字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg,dodge_skill;

        if(!target) target = offensive_target(me);
        if(!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神功震敌只能对战斗中的对手使用。\n");

        if(objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「震」字诀！\n");                
        
        if((int)me->query_skill("houquan", 1) < 150 )
                return notify_fail("你的猴拳不够娴熟，不会使用「震」字诀。\n");

        if((int)me->query_skill("force",1) < 150)
                return notify_fail("你的内功修为不够，不能使用「震」字诀。\n");

        if((int)me->query("neili") < 500)
                return notify_fail("你现在内力太弱，不能使用「震」字诀。\n");
                        
        if((int)me->query("jiali") <= 0)
                return notify_fail("你没有激发任何加力，「震」字诀将威力大减。\n");

        me->clean_up_enemy();

        msg = HIM"$N默运神功，使出猴拳中的「震」字诀，企图以内力震伤$n！\n"NOR;
        if(random(me->query("combat_exp")) > target->query("combat_exp") / 3 )
        {
                me->start_busy(2);
                damage = (int)me->query_skill("force", 1) + me->query("jiali") * 2;
                damage = damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("jing", damage/3,me);
                me->add("neili", -500);
                if( damage < 20 ) msg += HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
                else if( damage < 40 ) msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 80 ) msg += RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else msg += HIR"结果$n被$N的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
                
        } 
        else 
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += HIW + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        return 1;
}
