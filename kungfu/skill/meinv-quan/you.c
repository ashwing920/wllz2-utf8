// you.c 美女拳

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("古墓幽居只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须先放下手中的兵器！\n");

        if( (int)me->query_skill("meinv-quan", 1) < 120 )
                return notify_fail("你的美女拳级别不够，不会使用古墓幽居。\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你现在内力太弱，不能使用古墓幽居。\n");

        msg = HIW "$N右手支颐，左袖轻轻挥出，长叹一声，使出「古墓幽居」，脸现寂寥之意。\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force")/ 2 ){
                me->start_busy(2);
                damage = (int)me->query_skill("yunv-xinfa", 1) + (int)me->query_skill("meinv-quan",1);
                damage = (damage/4 + random(damage/4) + random(damage/5)) * me->query_per() / 6;
                target->receive_damage("qi", damage,me);
                target->start_busy(random(3));
                me->add("neili", - 200);
                if( damage < 50 )
                        msg += HIY"结果$n被$N袍袖一拂，闷哼一声。\n"NOR;
                else if( damage < 80 )
                        msg += HIY"结果$n被$N以袍袖一拂，「腾腾」地退出几步。\n"NOR;
                else if( damage < 120 )
                        msg += RED"结果$n被$N以袍袖一拂，胸口有如受到一记重锤，气血为之一窒！\n"NOR;
                else
                        msg += HIR"结果$n被$N的袍袖一拂，眼前一黑，浑身气血翻腾，竟如身入洪炉一般！\n"NOR;

        }
        else
        {
                me->start_busy(3);
                msg += CYN"可是$p看破了$P的企图，依然稳如泰山，抬手一架格开。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
