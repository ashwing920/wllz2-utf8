// fugu.c 金蛇游身掌-附骨缠身

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;

        if(!target) target = offensive_target(me);
        if(!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("附骨缠身只能对战斗中的对手使用。\n");

        if(objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你不是空手，不能使用附骨缠身。\n");

        if((int)me->query_skill("jinshe-zhang", 1) < 120 )
                return notify_fail("你的金蛇掌不够娴熟，不会使用附骨缠身。\n");

        if( (int)me->query("neili") < 200)
                return notify_fail("你现在内力太弱，不能使用附骨缠身。\n");

        me->clean_up_enemy();
        msg = HIC "$N大喝一声，缠身而上左手一探刁住$n手腕，右掌猛下杀手！\n"NOR;
        message_vision(msg, me, target);
        if (random(me->query_skill("strike")) > target->query_skill("dodge") / 3 )
        {
                msg = HIR"结果$n被$N的左手所制，在「附骨缠身」下，竟然无法还手！\n"NOR;
                message_vision(msg, me, target);
                for(i = 0; i < 3; i++)
                        if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                        if(me->query_temp("weapon")) break;
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                
                } else break;
                me->add("neili", -200);
                me->start_busy(random(3));
        }
        else
        {
                msg = CYN"可是$p识破了$P这一招，手肘一送，摆脱了对方控制。\n"NOR;
                message_vision(msg, me, target);
                me->add("neili",-100);
                me->start_busy(3);
        }
        return 1;
}
