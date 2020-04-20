// fengfei.c  落叶纷飞

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("落叶纷飞只能在战斗中使用。\n");
        if((int)me->query_skill("biyun-xinfa",1) < 120)
                return notify_fail( "你的碧云心法修为不够。\n" );
        if((int)me->query_skill("qiulinshiye",1) < 120)
                return notify_fail( "你的凌波微步不够熟练。\n" );
        if((int)me->query("neili") < 200)
                return notify_fail( "你现在内力不足。\n" );
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        msg = HIM"只见$N运起秋林拾叶中的精髓落叶纷飞，身法陡然加快，瞬间夹起数道劲起向$n袭去！\n"NOR;

        if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/ 3 ) {
                msg += HIW "只见数道劲气形成旋风，将$p围着转得头晕眼花，连退三步！\n" NOR;
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


