// yingfeng-steps.c - 迎风拂柳步

inherit SKILL;

string *dodge_msg = ({
        "只见$n施展迎风拂柳步，向一旁飘然纵出，轻轻着地。\n",
        "$n施展迎风拂柳步，尤如燕子一般，向一旁飘然纵出，避开了$N的攻击。\n",
        "$n身形往上一拔，施展迎风拂柳步，一个转折落在数尺之外。\n",
        "只见$n身影滴溜溜地一转，施展迎风拂柳步，飘忽若神。\n",
        "只见$n施展迎风拂柳步，轻轻巧巧地避了开去。\n",
        "可是$n施展迎风拂柳步，身子轻轻飘了开去。\n",
        "只见$n施展迎风拂柳步，身随意转，早已飘到$N身后。\n",
        "$n身影一幌，施展迎风拂柳步，身形如影随形，轻轻闪到一旁。\n",
});

int valid_enable(string usage) { return (usage=="dodge" || usage=="move") ; }

int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("你的内力修为不够，无法研习高深的步法。\n");
        if( (int)me->query_skill("force") < 10 )
                return notify_fail("你的内功火候不够，无法研习高深的步法。\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        int i;

        i = (int)me->query_skill("yingfeng-steps");
        if( (int)me->query("qi") < 35 )
                return notify_fail("你的气太少了，无法继续练习迎风拂柳步法。\n");
        me->receive_damage("qi", 35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yingfeng-steps/" + action;
}

