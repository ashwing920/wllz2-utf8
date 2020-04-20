// he.c 玉女素心剑-双剑合璧

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("双剑合璧只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("yunv-jian", 1) < 150 )
                return notify_fail("你的玉女素心剑不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query_skill("quanzhen-jian", 1) < 150 )
                return notify_fail("你的全真剑法不够娴熟，不能使用双剑合璧。\n");

        if( (int)me->query("neili") < 300)
                return notify_fail("你现在内力太弱，不能使用双剑合璧。\n");

        msg = YEL "$N左手以全真剑法剑意，右手化玉女素心剑剑招，双剑合璧同时刺出。\n"NOR;
        if (random(me->query_skill("force")) > target->query_skill("force")/2 ){
                me->start_busy(2);
                damage = (int)me->query_skill("yunv-jian", 1) + (int)me->query_skill("quanzhen-jian",1);
                damage = damage + (int)me->query_skill("yunv-xinfa",1) ;
                damage = damage/4 + random(damage);
                target->receive_damage("qi", damage,me);
                target->start_busy(2);
                me->add("neili", -300);

                msg += HIR"$n看到$N双剑飞舞，招式中所有破绽都为另一剑补去，竟不知如何是好！\n"NOR;
                msg += HIR"一呆之下，$N的剑招已经破式而入！\n"NOR;

        }
        else
        {
                me->start_busy(3);
                msg += CYN"可是$p看破了$P的企图，将自己的全身上下护得密不透风，令$P无计可施。\n"NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
