//dance.c 群魔乱舞

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("群魔乱舞只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if( (int)me->query_skill("pixie-jian",1) < 120 )
                return notify_fail("你的辟邪剑法不够娴熟，不会使用「群魔乱舞」。\n");
                                
        if( (int)me->query("neili") < 200)
                return notify_fail("你现在内力太弱，不能使用「群魔乱舞」。\n");
                        
        msg = CYN "$N邪恶的一笑，突然间面目狰狞，猛吸一口气，欲使出以气驭剑绝技攻击$n。\n"NOR;

        me->clean_up_enemy();
        if(random(me->query_skill("force")) > target->query_skill("force")/5 ){
        msg += HIR"只见$N手中剑光幻作一条金龙，腾空而起，倏的罩向$n，\n$n只觉数道剑气猛烈的袭来，登时眼前一花，两耳轰鸣，招架不及！！\n"NOR;
        message_vision(msg, me, target);
        for(i = 0; i < 8; i++)
                if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                        me->set_temp("action_flag",1);
                        if(!weapon->query("equipped")) break;
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                        me->set_temp("action_flag",0);
                }else break;
                        me->add("neili",-200);
                        me->start_busy(3);
        } 
        else 
                {
                msg += CYN"可是$p猛地向前一跃，跳出了$P的攻击范围。\n"NOR;
                message_vision(msg, me, target);
                me->add("neili", -100);
                me->start_busy(4);
        }
        return 1;
}
