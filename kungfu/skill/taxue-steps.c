// taxue-steps.c - 踏雪无痕

inherit SKILL;

string *dodge_msg = ({
        "只见$n身影一晃，一招「腾云驾雾」早已避在数尺之外。\n",
        "但见$n一招「鱼翔蓝天」，轻轻巧巧地避了开去。\n",
        "$n足下一点，一招「步履云端」腾空而起，避了开去。\n",
        "可是$n使一招「踏雪无痕」，身子轻轻飘了开去。\n",
        "但见$n身影微动，已经藉一招「龙腾万里」轻轻闪过。\n"
        "$n一招「移步换形」，足不动，手不抬，便绕到了$N的身后。\n",
        "只见$n一招「雨燕掠波」，向一旁飘然纵出，轻轻着地。\n",
        "$n一招「夕阳残雪」，一转身间，四面八方飘动着无数个$n的身影。\n",
});

int valid_enable(string usage) { return (usage=="dodge" || usage=="move") ; }

int valid_learn(object me)
{
        if( (int)me->query("max_neili") < 100 )
                return notify_fail("你的内力修为不够，无法研习高深的步法。\n");
        if( (int)me->query_skill("force",1) < 10 )
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

        i = (int)me->query_skill("taxue-steps");
        if( (int)me->query("qi") < 35 )
                return notify_fail("你的气太少了，无法继续练习踏雪无痕。\n");
        me->receive_damage("qi", 35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"taxue-steps/" + action;
}
