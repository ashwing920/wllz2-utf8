// regenerate.c

int exert(object me, object target)
{
        int n, q;
        if (target != me) 
                return notify_fail("你只能用内功恢复自己的精力。\n");
        
        q = (int)me->query("eff_jing") - (int)me->query("jing");
        if (q < 10)
                return notify_fail("你现在精力充沛。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够。\n");
        n = 100 * q / me->query_skill("force");
        n = 30 * n / me->query_con();
        if (n < 20)
                n = 20;
        if ((int)me->query("neili") < n) {
                q = q * (int)me->query("neili") / n;
                n = (int)me->query("neili");
        }
        me->add("neili", -n);
        me->receive_heal("jing", q);
        
        message_vision("$N深深吸了几口气，精神看起来好多了。\n", me);
                if( me->is_fighting() ) me->start_busy(1);
        return 1;
}
