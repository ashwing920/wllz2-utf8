// sui.c 随波逐流

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("随波逐流只能在战斗中使用。\n");

        if((int)me->query_skill("bibo-shengong",1) < 150)
                return notify_fail("你的碧波神功修为尚潜，无法发挥暗影浮香的威力。\n" );

        if((int)me->query_skill("anying-fuxiang",1) < 150)
                return notify_fail( "你的暗影浮香功力不足，无法发挥随波逐流。\n" );

        if((int)me->query("neili") < 300)
                return notify_fail( "你现在内力不足。\n" );

        if( target->is_busy())
                return notify_fail(target->name() + "已被你的招式所迷惑，赶紧放胆攻击吧！\n");

        if( me->query("gender") == "男性"){
        msg = HIW 
"$N凝神运气，步伐急速向前左右迈开；只见地面上骤时卷起一片
尘埃，漩涡般极速转起，犹如一道波浪，来势汹涌，气势澎湃，完
全不理$n如何出招，时左时右，直朝$n冲了过去。\n"NOR;
        }
        else   {
        msg = HIM
"$N脚步轻盈，步步生花，脚下尘土犹如一道轻烟飘然而起，形成
一道急流，来势汹涌，气势澎湃，完全不理$n如何出招，一路
直朝$n冲了过去，把$n包围了起来。\n"NOR;
        }

        if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/ 3 ) {
                msg += HIC"$N招式之快，步法之奇妙，看$n得眼花缭乱，半天回不过神来。\n" NOR;
                target->start_busy((int)me->query_skill("anying-fuxiang",1) / 50);
                me->add("neili", -200);
                me->start_busy(1);
        } else {
                msg += HIG"$n临危不乱，纵身凌空而起，跳出了$N的招式之中。\n" NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        return 1;
}
