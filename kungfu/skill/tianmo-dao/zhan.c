// by robert

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill,ap,dp,damage,i;

        skill = me->query_skill("tianmo-dao",1);

        if(!target) target = offensive_target(me);
        if(!target || !target->is_character()|| !me->is_fighting(target))
                return notify_fail("「天魔斩」只能对战斗中的对手使用。\n");

        if(!me->is_fighting())
                return notify_fail("「天魔斩」只能对战斗中的对手使用。\n");

        if(!objectp(weapon = me->query_temp("weapon"))
        ||(string)weapon->query("skill_type") != "blade")
                return notify_fail("你所使用的武器不对\n");

        if( skill < 150)
                return notify_fail("你的「天魔刀法」等级不够, 无法使用「天魔斩」！\n");

        if( me->query_skill("tianmo-dafa",1) < 150 )
                return notify_fail("你的天魔大法修为不够，无法使用「天魔斩」！\n");

        if( me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够，无法使用「天魔斩」！\n");

        if( me->query("neili") < 500 )
                return notify_fail("你的内力不够，无法运功！\n");

        me->clean_up_enemy();

        msg = HIC"$N手指刀柄，瞬间将全身真气聚于刀中，使出的正是天魔刀法中的真髓「"HIW"天魔斩"HIC"」！\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 400;
        dp = target->query("combat_exp") / 2;

        for(i = 0; i < 3; i++)
                if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;

        if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                msg = HIC"\n紧接着$N反身挥刀，刀光夹着一道强烈的内劲向$n的胸口砍去。\n"NOR;
                message_vision(msg, me, target);
        
                if( dp < 1 ) dp = 1;
                if( random(ap) > dp )
                {
                        COMBAT_D->do_attack(me, target, weapon,1);
                        msg = HIR"\n$n侧身闪避，刚想避开，却被刀气正中胸前，紧跟着眼前一黑，“哇”的一声喷出一口鲜血！\n"NOR;
                        damage = skill + (int)me->query_skill("tianmo-dafa",1);
                        damage = damage + random(damage);
                        target->receive_damage("jing",damage,me);
                        target->receive_wound("qi",damage / 2,me);
                        me->add("neili",-500);
                        me->start_busy(3);
                }
                else
                {
                        msg = HIW"只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                        me->add("neili",-200);
                        me->start_busy(4);
                }
        }
        message_vision(msg, me, target);
        return 1;
}
