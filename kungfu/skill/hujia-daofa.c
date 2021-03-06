// hujia-daofa.c 

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w横推，一招「推波助澜」，由上至下向$nl砍去  ",
        "skill_name" : "推波助澜",
        "force" : 80,
        "dodge" : -10,
        "parry" : 10,
        "lvl" : 10,
        "damage" : 40,
        "damage_type" : "割伤",
]),
([        "action" : "$N一招「沙鸥掠波」，刀锋自下而上划了个半弧，$w一提一收，平刃挥向$n的颈部  ",
        "skill_name" : "沙鸥掠波",
        "force" : 100,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 30,
        "damage" : 70,
        "damage_type" : "割伤",
]),
([        "action" : "$N使出一招「天设牢笼」，将$w舞得如白雾一般压向$n ",
        "skill_name" : "天设牢笼",
        "force" : 120,
        "dodge" : 10,
        "parry" : 10,
        "lvl" : 60,
        "damage" : 85,
        "damage_type" : "割伤",
]),
([        "action" : "$N一招「闭门铁扇」，$w缓缓的斜着向$n推去 ",
        "skill_name" : "闭门铁扇",
        "force" : 150,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 80,
        "damage" : 100,
        "damage_type" : "割伤",
]),
([      "action" : "$N手拖$w，转身跃起，一招「翼德闯帐」，一道白光射向$n的胸口 ",
        "skill_name" : "翼德闯帐",
        "force" : 200,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 120,
        "damage" : 125,
        "damage_type" : "割伤",
]),
([      "action" : "$N挥舞$w，使出一招「白鹤舒翅」，上劈下撩，左挡右开，齐齐罩向$n  ",
        "skill_name" : "白鹤舒翅",
        "force" : 230,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 150,
        "damage" : 135,
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「春风送暖」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l  ",
        "skill_name" : "春风送暖",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 200,
        "damage" : 160,
        "damage_type" : "割伤",
]),
([      "action" : "$N募的使一招「八方藏刀」，顿时剑光中无数朵刀花从四面八方涌向$n全身  ",
        "skill_name" : "八方藏刀",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 250,
        "damage" : 300,
        "damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_research() { return 100; }
int valid_learn(object me)
{
        if((int)me->query("max_neili") < 500 
        || (int)me->query_skill("force", 1) < 100)
                return notify_fail("你的内力修为不够，无法学习胡家刀法。\n");

        if((int)me->query("spi") < 22)
                return notify_fail("你的灵性太差，恐怕无法领会胡家刀法之中的精髓。\n");

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
        level = (int) me->query_skill("hujia-daofa",1);

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够，练不了胡家刀法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hujia-daofa/" + action;
}
