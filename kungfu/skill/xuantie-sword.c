     
// xuantie-sword.c - 玄铁剑法

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N拔步挺腰，一招「赵客缦胡缨，吴钩霜雪明」，手中$w挟著闪闪剑光刺向$n的$l",
        "force"         : 120,
        "dodge"         : 10,
        "parry"         : 10,
        "damage"        : 20,
        "lvl"           : 0,
        "skill_name"    : "赵客缦胡缨，吴钩霜雪明",
        "damage_type"   : "刺伤"
]),
([      "action" : "只见$N手中$w剑光暴长，一招「银鞍照白马，飒沓如流星」连刺$n几处要害",
        "force"         : 140,
        "dodge"         : 20,
        "parry"         : 20,
        "damage"        : 20,
        "lvl"           : 10,
        "skill_name"    : "银鞍照白马，飒沓如流星",
        "damage_type"   : "刺伤"
]),
([      "action" : "$N一招「十步杀一人，千里不留行」，手中$w狂风骤雨般地向$n的$l刺去",
        "force"         : 160,
        "dodge"         : 30,
        "parry"         : 30,
        "damage"        : 30,
        "lvl"           : 20,
        "skill_name"    : "十步杀一人，千里不留行",
        "damage_type"   : "割伤"
]),
([      "action" : "$N身形一转，一招「事了拂衣去，深藏身与名」，$w剑势如风，刺向$n的$l要害",
        "force"         : 180,
        "dodge"         : 40,
        "parry"         : 40,
        "damage"        : 40,
        "lvl"           : 30,
        "skill_name"    : "事了拂衣去，深藏身与名",
        "damage_type"   : "刺伤"
]),
([      "action" : "$N一招「闲过信陵饮，脱剑膝前横」，中宫直进，手中$w猛地刺向$n的$l",
        "force"         : 200,
        "dodge"         : 50,
        "parry"         : 50,
        "damage"        : 60,
        "lvl"           : 40,
        "skill_name"    : "闲过信陵饮，脱剑膝前横",
        "damage_type"   : "刺伤"
]),
([      "action" : "$N一招「三杯吐然诺，五岳倒为轻」，剑锋直出，绵绵不断,$w连刺$n几处要害",
        "force"         : 220,
        "dodge"         : 60,
        "parry"         : 60,
        "damage"        : 80,
        "lvl"           : 50,
        "skill_name"    : "三杯吐然诺，五岳倒为轻",
        "damage_type"   : "割伤"
]),
([      "action" : "$N一招「眼花耳热后，意气素霓生」，$n只觉得全身被笼罩在一团剑气之中。",
        "force"         : 240,
        "dodge"         : 70,
        "parry"         : 70,
        "damage"        : 100,
        "lvl"           : 60,
        "skill_name"    : "眼花耳热后，意气素霓生",
        "damage_type"   : "刺伤"
]),
([      "action" : "$N手中$w直指$n$l，一招「救赵挥金锤，邯郸先震惊」发出逼人剑气刺去",
        "force"         : 260,
        "dodge"         : 80,
        "parry"         : 80,
        "damage"        : 120,
        "lvl"           : 70,
        "skill_name"    : "救赵挥金锤，邯郸先震惊",
        "damage_type"   : "刺伤"
]),
([      "action" : "$N向前踏上一步，剑尖一点，一招「千秋二壮士，洹赫大梁城」缓缓刺向$n的$l",
        "force"         : 280,
        "dodge"         : 90,
        "parry"         : 90,
        "damage"        : 140,
        "lvl"           : 80,
        "skill_name"    : "千秋二壮士，洹赫大梁城",
        "damage_type"   : "刺伤"
]),
([      "action" : "$N潜运真力，一招「纵死侠骨香，不惭世上英」，$w划出无数圆圈，狂风骤起，笼罩天地",
        "force"         : 300,
        "dodge"         : 100,
        "parry"         : 100,
        "damage"        : 160,
        "lvl"           : 100,
        "skill_name"    : "纵死侠骨香，不惭世上英",
        "damage_type"   : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        object ob;
        
        if( me->query("gender") != "男性")
                return notify_fail("只有男性才可以学这种武功。\n");
        if((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够。\n");
        if((int)me->query_skill("xiantian-qigong",1) < 10)
                return notify_fail("你的先天气功修为不够，无法学习玄铁剑法！\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练玄铁剑法。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xuantie-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"]) return action[random(i)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练玄铁剑法。\n");
        me->receive_damage("qi", 35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-sword/" + action;
}
