// luanwu

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神功杀敌只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「乱」字诀！\n");

        if( (int)me->query_skill("wuying-shenquan", 1) < 200 )
                return notify_fail("你的无影神拳不够级别，不会使用「乱」字诀。\n");

        if( (int)me->query_skill("xuehai-mogong", 1) < 200 )
                return notify_fail("你的血刀心法不够高，不能用来伤敌。\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你现在内力太弱，不能使用「乱」字诀。\n");

        if((int)me->query("jiali") < 1)
                return notify_fail("你没有设置加力，「乱」字诀将形同虚设。\n");

        msg = HIR "$N大喝一声，运起无影神拳的终极绝技，陡然增加臂力，欲与$n同归于尽！\n"NOR;
        if(random(me->query_skill("force",1)) > target->query_skill("force",1)/2 ){
                me->start_busy(3);
                target->start_busy(random(3));
                damage = (int)me->query_skill("xuehai-mogong", 1) + (int)me->query_skill("wuying-shenquan",1);
                damage = damage + random(damage);
                damage = damage + me->query("jiali");
                target->receive_damage("qi", damage,me);
                target->receive_wound("jing",damage/3,me);
                if(damage > (int)me->query("neili"))
                me->set("neili",0);
                else
                me->add("neili", -damage);
                if( damage < 120 )
                        msg += HIY"结果$n受到$N的乱舞之拳的攻击，闷哼一声。\n"NOR;
                else if( damage < 140 )
                        msg += HIY"结果$n被$N的乱舞之拳一击，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 180 )
                        msg += RED"结果$n被$N的乱舞之拳一重击，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else
                        msg += HIR"结果$n被$N的乱舞之拳击中，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
        }
        else
        {
                target->start_busy(1);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
