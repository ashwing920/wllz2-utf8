// jiedu.c 解五毒神掌

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target )
{
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("你要给谁解毒。\n");

        if( (int)me->query_skill("wudu-zhang", 1) < 80 )
                return notify_fail("你的五毒神掌不够娴熟，不能解五毒神掌。\n");

        if( (int)me->query("neili", 1) < 100 )
                return notify_fail("你现在内力太弱，不能解毒。\n");
                
        if( !target->query_condition("wudu_poison"))
                return notify_fail(target->name()+"并没有中五毒神掌。\n");

        me->add("neili",-100);
        target->apply_condition("wudu_poison",0);
        msg = HIW "$N真气骤升，化为掌力，轻轻的向$n肩上拍去，$n吐出一口淤血，脸色好看多了。\n"NOR;
        message_vision(msg, me, target);
        return 1;
}
