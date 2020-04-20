// quick_attack.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage,i;

        if(!target) target = offensive_target(me);
        if(!target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("快速攻击只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不够。\n");

        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力修为不够。\n");

        if((int)me->query_skill("guimei-shenfa",1) < 150)
                return notify_fail("你的鬼魅身法还不够娴熟，无法使用快速攻击。\n");

        if((int)me->query_skill("wudu-shengong",1) < 200)
                return notify_fail("你的五毒神功修为不够，无法使用鬼魅身法的快速攻击。\n");

        i = me->query_skill("dodge") / 50;
        msg = HIW + BLK"\n只见$N施展绝顶轻功，幻成"+chinese_number(i)+"个鬼影，身形飘忽，向$n袭去！\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2){
                msg +=HIB"结果$p被$P攻了个措手不及！被$P的袭击打中！\n" NOR;
                if (me->query_temp("weapon")){
                        damage = (int)me->query_skill("guimei-shenfa",1) + (int)me->query_skill("force",1);
                        damage += me->query_temp("apply/damage");
                        target->receive_damage("qi",damage,me);
                        target->receive_wound("qi",damage / 2,me);
                }
                else{
                        damage = me->query_skill("guimei-shenfa",1);
                        damage += damage + random(damage);
                        target->receive_damage("jing",damage /2,me);
                }
                me->start_busy(2);
                me->add("neili",-300);
        }
        else {
                msg += HIC"\n可是$p早已全神贯注地防守$P了，所以总算没遭$P的暗算。\n" NOR;
                me->add("neili",-200);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        return 1;
}
