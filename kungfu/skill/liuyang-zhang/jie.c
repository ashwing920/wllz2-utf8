// /kungfu/skill/liuyang-zhang/jie.c 解生死符

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target )
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("你要给谁解生死符。\n");
        if(target == me)
                return notify_fail("你无法给自己解生死符！\n");
        if( (int)me->query_skill("bahuang-gong", 1) < 120 
           && (int)me->query_skill("beiming-shengong", 1) < 120)
                return notify_fail("你的内功心法不够娴熟，不能解生死符。\n");

        if( (int)me->query_skill("liuyang-zhang", 1) < 120 )
                return notify_fail("你的天山六阳掌不够娴熟，不能解生死符。\n");

        if( (int)me->query("neili", 1) < 300)
                return notify_fail("你现在内力太弱，不能解生死符。\n");

        me->add("neili", - 300);
        target->apply_condition("ss_poison", 0);
        msg = CYN "$N使出天山六阳掌，按解生死符的手法，快速的拍向$n的周身大穴。\n"NOR;

        message_vision(msg, me, target);
        return 1;
}
