// regenerate.c
//inherit SSERVER;

int exert(object me, object target)
{
        int j;
        if (target != me)
                return notify_fail("你只能用内功恢复自己的精力。\n");

        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够。\n");
        j = (int)me->query("max_jingli") - (int)me->query("jingli");
        if (j < 10)
                return notify_fail("你现在精力充沛。\n");

        me->add("neili", -20);
        me->receive_heal("jingli", (int)me->query_skill("force") / 3);

        message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);

        if(userp(me) && me->is_fighting()) me->start_busy(2);

        return 1;
}


