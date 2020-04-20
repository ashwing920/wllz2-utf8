// wmyz.c 亡命一击

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("亡命一击只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "throwing")
                        return notify_fail("你使用的武器不对。\n");
        if((int)me->query_skill("liuxing-dao",1) < 200)
                return notify_fail("你的流星赶月刀火候不足，无法使用亡命一击！\n");

        if((int)me->query_skill("biyun-xinfa",1) < 200)
                return notify_fail("你的碧云心法火候不足，无法使用亡命一击！\n");

        if(!present("fei dao",me))
                return notify_fail("你身上没有飞刀，不能使用流星赶月刀的「亡命一击」。\n");

        if( (int)me->query("neili") < 300)
                return notify_fail("你的内力不够，无法使用亡命一击。\n");

        msg = HIM"$N手法陡然增快，手中飞刀犹如流星般射向$n，使出的正是流星赶月刀的「亡命一击」！\n"NOR;

        if (random(me->query_skill("dodge")) > target->query_skill("dodge")/ 2 ){
                me->start_busy(2);
                damage = (int)me->query_skill("liuxing-dao", 1) + (int)me->query_skill("biyun-xinfa",1);
                damage = (damage/6 + random(damage/4) + random(damage/5)) * me->query_dex() / 10;
                target->receive_damage("qi", damage,me);
                me->add("neili", - 300);
                msg += HIR"$n闪躲不及，已被$N一击命中，飞刀正中胸膛。\n\n"NOR;
                
        }
        else
        {
                me->start_busy(4);
                msg += CYN"$p转身躲避，飞刀射中了$p的手臂！\n"NOR;
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}
