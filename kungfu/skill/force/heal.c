// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if ((int)me->query_skill("force") < 20)
                return notify_fail("你的内力修为还不够。\n");
        if( (int)me->query("neili") < 100 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if((int)me->query("eff_qi") >= (int)me->query("max_qi"))
                return notify_fail("你现在体力充沛，无需再进行疗伤了。\n");
        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",HIY+ me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,environment(me), me);

        me->receive_curing("qi", me->query("max_qi") / 20);
        me->add("neili", -50);
        me->start_busy(1);
        return 1;
}
