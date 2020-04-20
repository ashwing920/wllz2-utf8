
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「惊天一击」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xianglong-zhang", 1) < 180 )
                return notify_fail("你的降龙十八掌不够熟练，不会使用「惊天一击」。\n");

        if( (int)me->query_skill("huntian-qigong",1) < 180)
                return notify_fail("你的混天气功修为不够，无法使用「惊天一击」。\n");

        if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为还不够高。\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("你的内力不够了。\n");

        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");    

        msg = HIC "$N施展出降龙十八掌的绝学"HIY+"「惊天一击」"+HIC"，全身急速转动起来，越来越快，\n就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。\n"NOR;  

        if( random(me->query("combat_exp")) > target->query("combat_exp")/4) { 
                me->start_busy(2);
                damage = (int)me->query_skill("xianglong-zhang", 1)*2+(int)me->query_skill("force",1);
                damage = damage + random(damage*2);
                if( damage > ((int)me->query("neili") + 200))
                damage = (int)me->query("neili");
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                me->add("neili", -damage);
                msg += HIR"$n只见一阵旋风影中陡然现出$N的双掌，根本来不及躲避，被重重击中，\n五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);        
                return 1;
        } else
                {
                me->start_busy(3);
                me->add("neili",-400);   
                msg += HIG"$n看得分明，连忙提气纵身，以跳离了$N的掌力范围。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
