                                                              //Cracked by Kafei
//chunyang.c 纯阳拳


inherit SKILL;

mapping *action = ({
([      "action" : "$N施展「玄鹤捕食」，身子腾空跃起，两臂张开，如仙鹤临空，\n紧跟着右拳左掌突然随势向前疾探，打向$n$l",
        "force" : 150,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 0,
        "skill_name" : "玄鹤捕食",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手使出「金蛇戏龟」，左右虚晃几招，右拳“嗖”地一声\n从掌风中猛穿出来，击向$n的$l",
        "force" : 180,
        "dodge" : -5,
        "parry" : 15,
        "lvl" : 10,
        "skill_name" : "金蛇戏龟",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N气沉丹田，猛然怒喝一声，向前一个弓步，双掌「野马上槽」，带着风雷之声奋力击向$n",
        "force" : 220,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 20,
        "skill_name" : "野马上槽",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N腾空飞起，一式「黑虎掏心」，右拳对着$n胸口雷霆般猛捣过去",
        "force" : 240,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 30,
        "skill_name" : "黑虎掏心",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N往前一个猛冲，一式「二龙戏珠」，双拳突然同时击出，直取$n的双目",
        "force" : 300,
        "dodge" : 10,
        "parry" : 15,
        "lvl" : 40,
        "skill_name" : "二龙戏珠",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N上身向后一仰，正好避开$n的攻击，突然一转身，反手一招「麒麟反挂」，\n一把扭住$n臂膀，右拳却捣向$n的面门",
        "force" : 360,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 50,
        "skill_name" : "麒麟反挂",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N向前一个弓箭步，使出「青龙夺食」，一记勾拳，不顾一切地捣向$n",
        "force" : 420,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 60,
        "skill_name" : "青龙夺食",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N运起丹田之气，猛喝一声，突然一式「赤龙穿云」，右拳变的赤红，\n挟带着狂风，如雷似电捣往$n$l",
        "force" : 510,
        "dodge" : 15,
        "parry" : 15,
        "lvl" : 70,
        "skill_name" : "赤龙穿云",
         "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练纯阳拳必须空手。\n");
        if ((int)me->query_skill("xiantian-qigong", 1) < 15)
                return notify_fail("你的先天气功火候不够，无法学纯阳拳。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练纯阳拳。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
        if(level >= action[i]["lvl"])
                return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i,level;
        level = (int) me->query_skill("chunyang-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练纯阳拳。\n");
        me->receive_damage("jing", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"chunyang-quan/" + action;
}
