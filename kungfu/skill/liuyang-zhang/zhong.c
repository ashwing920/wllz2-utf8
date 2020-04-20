// zhong.c 种生死符

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
        string msg;
        int skill;
        skill = (int)me->query_skill("bahuang-gong",1);

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("生死符只能种在对手身上。\n");

        if( !me->is_fighting() )
                return notify_fail("生死符只能种在对手身上。\n");
        if( (int)me->query_skill("bahuang-gong", 1) < 120
        &&  (int)me->query_skill("beiming-shengong", 1) < 120)
                return notify_fail("你的内功心法不够娴熟，不能种生死符。\n");
        if( (int)me->query_skill("liuyang-zhang", 1) < 120 )
                return notify_fail("你的天山六阳掌不够娴熟，不能种生死符。\n");
        if (!objectp(obj=present("jiudai", me)))
                return notify_fail("你身上没有酒袋，不能化水为冰。\n");
        msg = CYN "$N化水为冰，凝于掌中，“嗖”的串到$n面前，手掌轻飘飘地拍向$n。\n";
        me->start_busy(1);

        if( random( (int)me->query_skill("liuyang-zhang",1)) > random(target->query_skill("dodge") ) ) {
                msg += HIW "结果$P在$p身上种下了生死符！\n" NOR;
                target->receive_damage("qi",skill + (int)me->query_str(),me);
                target->receive_wound("qi",skill / 2,me);
                target->receive_wound("jing",10,me);
                target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)*3) +
                target->query_condition("ss_poison"));
                me->start_busy(random(2));
        } else {
                msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        target->start_busy(1 + random(2));

        return 1;
}

