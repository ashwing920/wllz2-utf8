// fengfei.c  落叶纷飞

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("誓言空只能在战斗中使用。\n");
        if((int)me->query_skill("longxiang",1) < 120)
                return notify_fail( "你的龙象般若功修为不够。\n" );
        if((int)me->query_skill("shenkong-xing",1) < 120)
                return notify_fail( "你的身空行不够熟练。\n" );
        if((int)me->query("neili") < 200)
                return notify_fail( "你现在内力不足。\n" );
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        msg = HIM"只见$n使出一招「誓言空」，双足一点，身法陡然加快，瞬间跃起向$n袭去！\n"NOR;

        if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/ 4 ) {
                msg += HIW "只见$N犹如一道光影，将$p定在原地！\n" NOR;
                target->start_busy((int)me->query_skill("qiulinshiye",1) / 50);
                me->add("neili", -200);
                me->start_busy(1);
        } else {
                msg += HIG "$p却是早有防备，跳出几丈之远，避开$P猛烈的攻击。\n" NOR;
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        return 1;
}


