// shexing-diaoshou.c 蛇形刁手

inherit SKILL;

mapping *action = ({
([      "action" : "$N左掌护胸，右臂微举作蛇形，续而向外疾伸，一式「灵蛇出洞」攻向$n的$l",
        "force" : 140,
        "dodge" : 10,
        "damage_type" : "瘀伤",
        "lvl" : 0,
        "skill_name" : "灵蛇出洞"
]),
([      "action" : "$N大叫一声使出「虎头蛇尾」，右手虚晃掩饰中；左手从$n意想不到之处疾抓其$l",
        "force" : 180,
        "dodge" : -5,
        "damage_type" : "抓伤",
        "lvl" : 5,
        "skill_name" : "虎头蛇尾"
]),
([      "action" : "$N使出「画蛇添足」，双手向$n抓去，同时又无声无息地一脚踢向$n的$l",
        "force" : 200,
        "dodge" : 0,
        "damage_type" : "跌伤",
          "lvl" : 10,
        "skill_name" : "画蛇添足"
]),
([      "action" : "只见$N跌扑于地，趁着$n向前探视，突然蹦起使出「杯弓蛇影」，向$n连抓几把",
        "force" : 230,
        "dodge" : -5,
        "damage_type" : "抓伤",
        "lvl" : 20,
        "skill_name" : "杯弓蛇影"
]),
([      "action" : "$N突然抱头欲逃，但却莫明其妙地滚近$n发出凌厉的攻势，好一招「蛇行鼠窜」",
        "force" : 260,
        "dodge" : 15,
        "damage_type" : "跌伤",
        "lvl" : 30,
        "skill_name" : "蛇行鼠窜"
]),
([      "action" : "$N一式「蛇鹰互搏」，双手带着嘶嘶破空之声，猛烈迅速地尽往$n上身要害攻击",
        "force" : 300,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "lvl" : 38,
        "skill_name" : "蛇鹰互搏"
]),
([      "action" : "$N双手徊旋中幻出万道蛇影，一招「万蛇汹涌」，诡异奇玄、铺天盖地推向$n",
        "force" : 330,
        "dodge" : 0,
        "damage_type" : "跌伤",
        "lvl" : 46,
        "skill_name" : "万蛇汹涌"
]),
([      "action" : "$N出其不意地使一式「白蛇吐信」，右手食中两指微分，闪电般地往$n的$l猛捅",
        "force" : 380,
        "dodge" : 0,
        "damage_type" : "瘀伤",
        "lvl" : 55,
        "skill_name" : "白蛇吐信"
]),
([      "action" : "突见$N双臂柔若无骨地伸缩着，使出「蛇磐青竹」缠住$n，右臂却悄悄地从不可思议处抹到$n的$l",
        "force" : 420,
        "dodge" : 5,
        "damage_type" : "跌伤",
        "lvl" : 65,
        "skill_name" : "蛇磐青竹"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练蛇形刁手必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
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
        int i, level;
        level   = (int) me->query_skill("shexing-diaoshou", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练蛇形刁手。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"shexing-diaoshou/" + action;
}
