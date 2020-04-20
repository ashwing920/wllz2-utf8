//huifeng-jian.c 回风拂柳剑

inherit SKILL;

mapping *action = ({
([      
        "skill_name":   "清风袭月",
        "action" : "$N剑尖剑芒暴长，一招「清风袭月」，手中$w自左下大开大阖，一剑向右上向$n的$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 300,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "飘雪穿云",
        "action" : "$N长剑圈转，一招「飘雪穿云」，手中$w平展下刺，一剑轻轻划过$n的$l",
        "force" : 120,
        "dodge" : 20,
        "damage" : 280,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "千峰竞秀",
        "action" : "$N长剑轻灵跳动，剑随身长，右手$w使出一式「千峰竞秀」刺向$n的$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 350,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "万流归宗",
        "action" : "$N长剑下指，剑意流转，一招「万流归宗」直取$n的$l",
        "force" : 150,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "乌龙搅柱",
        "action" : "$N剑芒吞吐，幻若灵蛇，右手$w使出一式「乌龙搅柱」，剑势曼妙，刺向$n的$l",
        "force" : 130,
        "dodge" : 25,
        "damage" : 300,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "大雁啼沙",
        "action" : "$N屈腕云剑，剑光如彩碟纷飞，幻出点点星光，右手$w使出一式「大雁啼沙」跃跃洒洒飘向$n的$l",
        "force" : 120,
        "dodge" : 25,
        "damage" : 320,
        "lvl" : 120,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "进退龙游",
        "action" : "$N挥剑分击，剑势自胸前跃出，右手$w一式「进退龙游」，毫无留恋之势，刺向$n的$l",
        "force" : 110,
        "dodge" : 15,
        "lvl" : 150,
        "damage" : 400,
        "damage_type" : "刺伤"
]),
([      "skill_name":   "天地鹤翔",
        "action" : "$N退步，左手剑指划转，腰部一扭，右手$w一记「天地鹤翔」自下而上刺向$n的$l",
        "force" : 150,
        "dodge" : 35,
        "damage" : 400,
        "lvl" : 180,
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候太浅。\n");
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
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练回风拂柳剑。\n");
        me->receive_damage("qi", 10);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}
