// jing.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中疗精？找死吗？\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 50)
                return notify_fail("你的先天神功修为还不够。\n");
        if( (int)me->query("neili") < 50 ) 
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
                return notify_fail("你的精损伤太多，只怕一运真气便有生命危险！\n");
                
        if((int)me->query("eff_jing") >= (int)me->query("max_jing"))
                return notify_fail("你现在的精力正常！\n");

        write( HIW "你全身放松，坐下来开始打座疗精。\n" NOR);
        message("vision",
                HIW + me->name() + "头上冒出屡屡热气，精神看起来好多了。\n" NOR,
                environment(me), me);

        me->receive_curing("jing", 10 + (int)me->query_skill("xiantian-qigong",1)/10 );
        me->add("neili", -50);
        me->set("jiali", 0);
        me->start_busy(4);

        return 1;
}
