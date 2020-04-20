// xian.c  云龙三现

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg,dodge_skill;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("云龙三现只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("yunlong-jian", 1) < 150 )
                return notify_fail("你的云龙剑法不够娴熟，不会使用「云龙三现」。\n");

        if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
                return notify_fail("你的云龙神功不够高，不能用来反震伤敌。\n");

        if( (int)me->query_skill("yunlong-xinfa",1) < 150)
                return notify_fail("你的云龙心法不够娴熟，还不能运用「云龙三现」。\n");

        if( (int)me->query("neili", 1) < 500)
                return notify_fail("你现在内力太弱，不能使用「云龙三现」。\n");

        me->clean_up_enemy();
        msg = HIY"$N微微一笑，猛吸一口气，欲使出以气驭剑绝技攻击$n。\n"NOR;
        if (random(me->query("combat_exp")) > target->query("combat_exp") / 3 ){
                damage = (int)me->query_skill("yunlong-xinfa", 1);
                damage += (int)me->query_skill("yunlong-shengong", 1) + (int)me->query_skill("yunlong-jian", 1);
                target->receive_wound("qi", damage / 2,me);
                me->add("neili",- 500);
                msg += HIR"只见$N手中剑光幻作一条金龙，腾空而起，倏的罩向$n。\n"NOR;
                msg += HIR"$n只觉一股大力铺天盖地般压来，登时眼前一花，两耳轰鸣，哇的喷出一口鲜血！！\n"NOR;
                me->start_busy(3);
        } else
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += HIW + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
                me->add("neili", -200);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        return 1;
}
